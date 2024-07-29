/*
https://www.geeksforgeeks.org/problems/burning-tree/1

Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Examples :

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value
8 is set on fire.
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.


Input:
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    /
 8    10
Target Node = 10
Output: 5

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ n ≤ 104

*/

// Step 1 -> find target node
// step 2 -> create node to parent map so that we can go upward in a tree
// void NodeToParentMapAndFindTarget(Node * root, unordered_map <Node*,Node*> &m, Node* parent, int target, Node* &targetNode){
//     if(root == NULL){
//         return ;
//     }

//     m[root] = parent;

//     if(root -> data == target){
//         targetNode = root;
//     }

//     NodeToParentMapAndFindTarget(root -> left, m, root, target, targetNode);
//     NodeToParentMapAndFindTarget(root -> right, m, root, target, targetNode);
// }

// Or for NodeToParentMapAndFindTarget -> simply do Lvl order traversal and find
void NodeToParentMapAndFindTarget(Node *root, unordered_map<Node *, Node *> &m, int target, Node *&targetNode)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    m[root] = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        // find target Node
        if (front->data == target)
        {
            targetNode = front;
        }

        if (front->left)
        {
            m[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            m[front->right] = front;
            q.push(front->right);
        }
    }
}

int burningTree(Node *targetNode, unordered_map<Node *, Node *> &m)
{
    unordered_map<Node *, bool> isVisited;
    queue<Node *> q; // will store currently burning nodes
    int T = 0;

    q.push(targetNode);
    isVisited[targetNode] = true;

    while (!q.empty())
    {
        int size = q.size();
        bool isFireSpreaded = false;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            // left child
            if (front->left && isVisited[front->left] != true)
            {
                q.push(front->left);
                isFireSpreaded = true;
                isVisited[front->left] = true;
            }

            // right child
            if (front->right && isVisited[front->right] != true)
            {
                q.push(front->right);
                isFireSpreaded = true;
                isVisited[front->right] = true;
            }

            // parent
            if (m[front] && isVisited[m[front]] != true)
            {
                q.push(m[front]);
                isFireSpreaded = true;
                isVisited[m[front]] = true;
            }
        }
        // increment time after we burn all nodes at time
        if (isFireSpreaded)
        {
            T++;
        }
    }
    return T;
}

int minTime(Node *root, int target)
{
    // Your code goes here
    unordered_map<Node *, Node *> m;
    Node *targetNode = NULL;
    NodeToParentMapAndFindTarget(root, m, target, targetNode);

    return burningTree(targetNode, m);
}