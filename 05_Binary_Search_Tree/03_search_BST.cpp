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


// Search in BST
bool searchInBST(node *root, int target){
    if(root == NULL){
        return false;
    }

    if(root -> data == target){
        return true;
    }

    bool leftAns = false;
    bool rightAns = false;

    if(target > root -> data){
        rightAns = searchInBST(root -> right, target);
    }

    else{
        leftAns = searchInBST(root -> left, target);
    }

    return leftAns || rightAns;
}

int main(){

    node *root = NULL;
    root = generateBST(root);   

    int target;
    cout<<"Enter what u want to search "<<endl;
    cin >> target;
    cout<< searchInBST(root, target)<<endl;

    cout<<"Enter what u want to search "<<endl;
    cin >> target;
    cout<< searchInBST(root, target)<<endl;

    return 0;
}

// Observation -> in Order traversal of BST is in sorted order
// TC = O(N), in case of skew symmetric tree, and O(log n) in perfect binary tree
// OR O(height)