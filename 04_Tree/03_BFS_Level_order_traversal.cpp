#include <iostream>
#include <queue>
using namespace std;

// Level order traversal or BFS
// Use queue to keep track of left to right elements
// Algo

// A - Initial state
// push root element in queue

// B - 
// fetch front element from q
// push its left element in q (if lchild not null)
// push its right element in q (if rchild not null)


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


void BFS(Node *root,  queue<Node*> &q){

    if(root == NULL){
        return ;
    }

    // Initial state
    else if(root != NULL){
        q.push(root);
    }

    while(!q.empty()){
        // fetch first node
        Node *first = q.front();
        q.pop();

        cout<<first->data<<" ";

        // push l and r child
        if(first->left){
            q.push(first->left);
        }
        if(first->right){
            q.push(first->right);
        }
    }
}


// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

// But the problem is that it is printing everything in same line, but we need to print level wise
// so use marker with queue -> which indicates 1 level is over

// algo
// A- Initial state 
// push front
// push NULL bec that lvl completed

// B- 
// Fetch front ->
// i) if NULL, means till here previous level traversed and all its childs are in queue, so push(NULL)
// ii) if not NULLL -// push its left element in q (if lchild not null) // push its right element in q (if rchild not null)


void BFS2(Node *root,  queue<Node*> &q){

    if(root == NULL){
        return ;
    }

    // Initial state
    else if(root != NULL){
        q.push(root);
        q.push(NULL); // since 0th level completed
    }

    while(!q.empty()){
        // fetch first node
        Node *first = q.front();
        q.pop();


        // Note - infinite loop here for last NULL, so manage this
        if(first == NULL && q.size()>0){
            cout<<endl;
            q.push(NULL);
        }
        else if(first != NULL){
            cout<<first->data<<" ";

            // push l and r child
            if(first->left){
                q.push(first->left);
            }
            if(first->right){
                q.push(first->right);
            }
        }
    }
}

int main()
{
    // tree
    //           5
    //         /   \
    //       20     30
    //      /  \   /  \
    //     50  70  60 100
    //    / \
    //   65  90

    Node *root = new Node(5);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(50);
    root->left->right = new Node(70);

    root->right->left = new Node(60);
    root->right->right = new Node(100);

    root->left->left->left = new Node(65);
    root->left->left->right = new Node(90);


    // Initial state
    queue<Node*> q;
    

    // BFS(root,q);
    // cout<<endl;

    cout<<"Level wise \n";
    BFS2(root,q);
    return 0;
}