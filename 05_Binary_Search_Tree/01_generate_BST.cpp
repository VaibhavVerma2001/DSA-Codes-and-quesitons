#include<iostream>
#include<vector>
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

void preOrder(node * root){ // NLR
    if(root == NULL){
        return ;
    }

    cout << root -> data <<" ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(node * root){ // LNR
    if(root == NULL){
        return ;
    }

    inOrder(root -> left);
    cout << root -> data <<" ";
    inOrder(root -> right);
}

void postOrder(node * root){ // LRN
    if(root == NULL){
        return ;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data <<" ";
}

int main(){

    node *root = NULL;
    root = generateBST(root);

    // cout<<root -> data <<" root data"<<endl;

    cout << "lvl order is : ";
    lvlOrder(root);
    cout<<endl;


    cout<<"preOrder is : ";
    preOrder(root);
    cout<<endl;

    cout<<"inOrder is : ";
    inOrder(root);
    cout<<endl;

    cout<<"postOrder is : ";
    postOrder(root);
    cout<<endl;

    return 0;
}

// Observation -> in Order traversal of BST is in sorted order
// TC = O(N), in case of skew symmetric tree, and O(log n) in perfect binary tree