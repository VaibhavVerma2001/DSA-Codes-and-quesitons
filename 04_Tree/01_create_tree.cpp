// Create Tree
// Step 1 - Create node
// Step 2 - Create left subtree
// Step 3 - Create right subtree

#include<bits/stdc++.h>
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

Node* createTree(){
    cout<<"Enter data of Node : "<<endl;
    int data;
    cin>>data;

    // BC
    if(data == -1){
        return NULL;
    }

    // Step 1 - Create node
    Node *root = new Node(data);

    // step 2 - Create left subtree
    root -> left = createTree();

    // Step 3 - Create right subtree
    root -> right = createTree();

    return root;
}


int main(){

    Node *root = createTree();
    cout<<root->data<<endl;
    return 0;
}