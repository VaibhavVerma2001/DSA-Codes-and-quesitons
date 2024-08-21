// Balaced BST means where diff between height of left adn right subtree <= 1 
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// Logic -> divide array in 2 parts --> create new node with arr[mid] then root -> start to mid - 1 and root -> right = mid + 1 to end.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class node {
    public :
    int data ;
    node *left;
    node *right;

    node(int data){
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
};


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


// Gnerate balanced bst from inorder
node* generateBSTfromInorder(vector<int> &inOrder, int start,int end){
    // BC 
    if(start > end){
        return NULL;
    }

    int mid = start + (end - start)/2;

    //Create node
    node *root = new node (inOrder[mid]);

    root -> left = generateBSTfromInorder(inOrder,start, mid-1);
    root -> right = generateBSTfromInorder(inOrder,mid + 1, end);

    return root;
}


void inorder(node *root){
    if(!root){return ;}

    inorder(root -> left);
    cout<<root -> data << " ";
    inorder(root -> right);
}



int main (){
    vector<int> inOrder;
    inOrder.push_back(10); inOrder.push_back(20); inOrder.push_back(30); inOrder.push_back(40);inOrder.push_back(50);inOrder.push_back(60);inOrder.push_back(70);

    int start = 0 , end = inOrder.size() - 1; 
    node * root = generateBSTfromInorder(inOrder, start, end);
    cout<<"lvl order traversal after creating tree is : "<< endl;
    lvlOrder(root);

    cout<<"\nin order traversal after creating tree is : "<< endl;
    inorder(root);

    return 0;
}