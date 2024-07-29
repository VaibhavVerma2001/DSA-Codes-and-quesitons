#include<iostream>
using namespace std;

class Node {
    public :

    int data;
    Node *left;
    Node *right;

    Node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


// TC for all -> O(N)
// SC for all -> O(N) -> skew tree in worst case

// 1 - Preorder -> NLR
void preOrderTraversal(Node *root){
    // BC
    if(root == NULL){
        return;
    }

    cout<<root -> data <<" ";

    // Left
    preOrderTraversal(root -> left);
    // right
    preOrderTraversal(root -> right);
}


// 2 - Inorder -> LNR
void inOrderTraversal(Node *root){
    // BC
    if(root == NULL){
        return;
    }


    // Left
    inOrderTraversal(root -> left);

    cout<<root -> data <<" ";
    // right
    inOrderTraversal(root -> right);
}


// 3 - Postorder -> NLR
void postOrderTraversal(Node *root){
    // BC
    if(root == NULL){
        return;
    }


    // Left
    postOrderTraversal(root -> left);
    // right
    postOrderTraversal(root -> right);
    cout<<root -> data <<" ";
}

int main(){
    Node *root = new Node(5);
    root -> left = new Node(10);
    root -> right = new Node(20);
    
    root -> left -> left = new Node(15);

    // tree
    //           5
    //         /  \
    //       10    20
    //      /  \   / \
    //     15
    //    / \

    preOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;
    return 0;
}