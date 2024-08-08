// Find minimum element in BST
// --> it will be left most leaf node

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


void inOrder(node * root){ // LNR
    if(root == NULL){
        return ;
    }

    inOrder(root -> left);
    cout << root -> data <<" ";
    inOrder(root -> right);
}


// Method 1 - inorder traversal , element at 0th index

// Method 2 - recursion
void minElement(node *root, int &mini){
    if(root == NULL){
        return ;
    }

    mini = min(mini, root -> data);

    minElement(root -> left, mini);    
}

// Method 3 - while loop -> find left most leaf
int minElement2(node *root){
    while(root -> left){
        root = root -> left;
    }
    return root -> data;
}



// similarly max element
int maxElement(node *root){
    while(root -> right){
        root = root -> right;
    }
    return root -> data;
}

int main(){

    node *root = NULL;
    root = generateBST(root);   

    cout<<"Inorder traversal is : "<<endl;
    inOrder(root);

    int mini = INT_MAX;
    minElement(root, mini);
    cout<< "\nminimum element is : "<<mini<<endl;

    mini = minElement2(root);
    cout<< "minimum element is : "<<mini<<endl;

    
    int maxi = maxElement(root);
    cout<< "\nmaximum element is : "<<maxi<<endl;

    return 0;
}

// Observation -> in Order traversal of BST is in sorted order
// TC = O(N), in case of skew symmetric tree, and O(log n) in perfect binary tree
// OR O(height)