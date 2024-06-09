/*

https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

*/

#include<bits/stdc++.h>
using namespace std ;


class node{
    public :
    int data;
    node *left;
    node *right;

    node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void BFS(node *root){

    if(root == NULL){
        return ;
    }

    // initial state
    queue <node *> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;

            if(q.size() > 0){
                q.push(NULL);
            }
        }
        else{
            cout<<front -> data<<" ";

            if(front->left){
                q.push(front->left);
            }

            if(front->right){
                q.push(front->right);
            }
        }
    }
}

// print root to first leaf node (excluding leaf) found
void printLeftBoundary(node *root){
    if(root == NULL){
        return ;
    }

    if(root -> left == NULL && root -> right == NULL){
        return ;
    }

    cout<<root -> data <<" ";

    // print only either left or right side, if lchild is not there then only go to right side
    if(root -> left){
        printLeftBoundary(root -> left);
    }
    else{
        printLeftBoundary(root -> right);
    }
}

// print right boundary bottom to top
void printRightBoundary(node *root){
    if(root == NULL){
        return ;
    }

    if(root -> left == NULL && root -> right == NULL){
        return ;
    }

    

    // print only either left or right side, if lchild is not there then only go to right side
    // first for right then left
    if(root -> right){
        printRightBoundary(root -> right);
    }
    else{
        printRightBoundary(root -> left);
    }

    cout<<root -> data <<" ";
}

// print leaf left to right
void printLeaf(node *root){
    if(root == NULL){
        return ;
    }

    if(root -> left == NULL && root -> right == NULL){
        cout<<root -> data <<" ";
    }

    printLeaf(root -> left);
    printLeaf(root -> right);
}


void printBoundary(node *root){
    if(root == NULL){
        return;
    }

    cout<< root -> data<<" ";
    printLeftBoundary(root -> left);
    // divide leaf in 2 parts otherwise
    // eg tree- 1
    // op = 1
    // but our code will give 1 1 , will print leaf again bec root isleaf
    // so leave root node and handle left, right subtree seperately
    printLeaf(root->left);
    printLeaf(root->right);
    printRightBoundary(root -> right);


    // if there is no right boundary then no need to print
    // eg tree = 4 10 N 5 5 N 6 7 N 8 8 N 8 11 N 3 4 N 1 3 N 8 6 N 11 11 N 5 8
    // op = 4 10 5 6 8 11 3 5 8 8 6 11 11
}

int main ()
{
    node *root = new node (10);

    root -> left = new node(20);
    root -> left -> left = new node(40);
    root -> left -> right = new node(50);
    root -> left -> right -> right = new node(80);
    root -> left -> right -> left = new node(70);
    root -> left -> right -> left -> left = new node(110);
    root -> left -> right -> left -> right = new node(111);

    root -> right = new node(30);
    root -> right -> right= new node(60);
    root -> right -> right -> right= new node(90);
    
    root -> right -> right -> right -> left= new node(112);
    root -> right -> right -> right -> right= new node(113);

    /*
    tree 

          10
       /      \
     20        30
   /    \        \
  40    50       60
        /  \       \
       70   80      90
      /  \         /  \
     110  111     112  113


    outout = 10 20 40 110 111 112 113 90 60 30 
    */

    // BFS(root);


    printBoundary(root);


    return 0 ;
}