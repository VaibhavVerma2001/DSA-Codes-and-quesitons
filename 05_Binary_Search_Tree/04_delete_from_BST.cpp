// https://leetcode.com/problems/delete-node-in-a-bst/description/

#include<iostream>
#include<queue>
using namespace std;

class node{
    public :
    int data;
    node *left;
    node *right;

    node (int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

node* insertInBST(node* root, int data){
    // if root NULL then create Node and return root
    if(root == NULL){
        node *newNode = new node(data);
        return newNode;
    }

    if(data > root -> data){
        root -> right = insertInBST(root -> right, data); // Link
    }

    else{
        root -> left = insertInBST(root -> left, data); // Link
    }

    return root;
}

node * generateBST(node* root){
    while(true){
        int data ;
        cout<<"Enter data : "<<endl;
        cin >> data;

        if(data == -1){
            break;
        }
        
        root = insertInBST(root, data);
    }

    return root;
}


void inOrder(node * root){ // LNR
    if(root == NULL){
        return ;
    }

    inOrder(root -> left);
    cout << root -> data <<" ";
    inOrder(root -> right);
}

int maxElement(node *root){
    while(root -> right){
        root = root -> right;
    }
    return root -> data;
}

void lvlOrder(node * root){
    if(root == NULL) {return ;}
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front -> data << " ";

            if(front -> left){
                q.push(front -> left);
            }

            if(front -> right){
                q.push(front -> right);
            }
        }
    }
}


// Delete from BST 
// 4 Cases 
// 1 -> leaf node --> directly return NULL
// 2 -> left null but right not null -> return root -> right
// 3 -> left not null but right null -> return root -> left
// 4 -> intern node --> 2 ways
// either replace it with biggest node of left subtree then delete that biggest node
// or replace it with smallest node of right subtree then delete that smallest node

node * deleteFromBST(node *root, int target){
    if(root == NULL){
        return NULL;
    }

    if(root -> data == target){
        // 4 cases

        // 1 -> leaf node
        if(root -> left == NULL && root -> right == NULL){
            delete root ;
            return NULL;
        }

        // case 2 -> left null but right not null
        else if(root -> left == NULL && root -> right != NULL){
            node *rightSubTree = root -> right;
            delete root;
            return rightSubTree;
        }

        // case 3 -> left null but right not null
        else if(root -> left != NULL && root -> right == NULL){
            node *leftSubTree = root -> left;
            delete root;
            return leftSubTree;
        }

        // case 4 -> internal node
        else{
            // find max node at left
            int maxi = maxElement(root -> left);
            
            // replacement
            root -> data = maxi;

            // now delete that node
            root -> left = deleteFromBST(root->left,maxi);
            return root ;
        }
    }

    else if (root -> data > target){
        root -> left = deleteFromBST(root -> left, target);
    }
    else{
        root -> right = deleteFromBST(root -> right, target);
    }

    return root; // Very important to return updated root
}




int main(){

    node *root = NULL;
    root = generateBST(root);   

    cout<<"\nLevel order"<<endl;
    lvlOrder(root);

    cout<<"\nInorder traversal"<<endl;
    inOrder(root);    


    while(true){
        int target;
        cout<<"\nEnter target to delete : ";
        cin>> target;

        if(target == -1){
            break;
        }

        root = deleteFromBST(root,target);

        cout <<"\n \nAfter deletion" <<endl << endl;

        cout<<"\nLevel order"<<endl;
        lvlOrder(root);

        cout<<"\nInorder traversal"<<endl;
        inOrder(root);  
    }
    

    return 0;
}

// Observation -> in Order traversal of BST is in sorted order
// TC = O(N), in case of skew symmetric tree, and O(log n) in perfect binary tree
// OR O(height)