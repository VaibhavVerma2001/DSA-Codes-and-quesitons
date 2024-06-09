/*
https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /   \    / \
  4     5   6    7
   \
    8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Your Task:
You just have to complete the function leftView() that returns an array containing the nodes that are in the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 100
0 <= Data of a node <= 1000

*/
#include<bits/stdc++.h>
using namespace std ;

// Logic-
// Since in level order traversal -> first node is left most node


// So method 1 - iteratively
// when front is NULL and q is not empty means now at front we have left most child of next level, so store that
vector<int> leftView(Node *root)
{
    // Your code here
    if(root == NULL){
        return {};
    }

    vector<int> leftview;
    
    queue<Node*> q;
    // initial state
    q.push(root);
    q.push(NULL);
    // store 1st level leftmost element
    leftview.push_back(root->data);


    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            // when NULL and q is not empty means now at front we have left most child of next level
            if(q.size() > 0){
                Node *first =  q.front();
                leftview.push_back(first->data);

                q.push(NULL);
            }
        }
        else{
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
    }
    return leftview;
}


// Method 2 - recursively
// Notice at each level size of vector == level(eg at lvl 0 leftview vector size = 0, at lvl 1 leftview vector size = 1 , ans so on...)
// so check if vector size == lvl then store that element and make root->left call first bec we need left most node

void solve(Node *root, int lvl,vector<int> &ans){
    if(root == NULL){
        return ;
    }
    
    if(ans.size() == lvl){
        ans.push_back(root->data);
    }
    
    solve(root->left,lvl + 1,ans);
    solve(root->right,lvl + 1,ans);
}

vector<int> leftView(Node *root){
    vector<int> ans;
    int lvl = 0;
    solve(root,lvl,ans);
    return ans;
}