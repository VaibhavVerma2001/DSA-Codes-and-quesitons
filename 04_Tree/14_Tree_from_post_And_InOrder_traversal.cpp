// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// To generate tree we must need
// 1 - inorder + preorder
// OR
// 2 - inorder + postorder
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// V.V. IMP -> take postorder index by reference so that it remains different for each call and not same for multiple calls
// And first call for root->right then root->left bec LRN -> so its right after node
// TC = SC = O(N)
Node *solve(vector<int> postorder, vector<int> inorder, int &postOrderIndex, int inOrderStart, int inOrderEnd, int size, unordered_map<int, int> &m)
{
    // BC
    if (postOrderIndex < 0 || (inOrderStart > inOrderEnd))
    {
        return NULL;
    }

    // Solve 1 case -> create Node for each preOrderIndex
    Node *root = new Node(postorder[postOrderIndex]);
    // increment index
    postOrderIndex--;

    // find its position in Inorder
    // int position = find(begin(inorder),end(inorder),root->data) - inorder.begin();
    int position = m[root->data];

    // for right -> position+1 -> inOrderEnd
    root->right = solve(postorder, inorder, postOrderIndex, position + 1, inOrderEnd, size, m);

    // for left -> inOrderStart -> position-1
    root->left = solve(postorder, inorder, postOrderIndex, inOrderStart, position - 1, size, m);

    return root;
}

void createMap(vector<int> in, unordered_map<int, int> &m)
{
    for (int i = 0; i < in.size(); i++)
    {
        m.insert({in[i], i});
    }
}

void BFS(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;

    // Initial state
    q.push(root);
    q.push(NULL); // since 0th level completed

    while (!q.empty())
    {
        // fetch first node
        Node *first = q.front();
        q.pop();

        // Note - infinite loop here for last NULL, so manage this
        if (first == NULL && q.size() > 0)
        {
            cout << endl;
            q.push(NULL);
        }
        else if (first != NULL)
        {
            cout << first->data << " ";

            // push l and r child
            if (first->left)
            {
                q.push(first->left);
            }
            if (first->right)
            {
                q.push(first->right);
            }
        }
    }
}

int main()
{
    // tree
    //            2
    //         /    \
    //        8      4
    //      /  \      \
    //     10   6      12

    vector<int> postorder = {10, 6, 8, 12, 4, 2};
    vector<int> inorder = {10, 8, 6, 2, 4, 12};

    unordered_map<int, int> m;
    createMap(inorder, m);

    int size = postorder.size();
    int postOrderIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;

    Node *root = solve(postorder, inorder, postOrderIndex, inOrderStart, inOrderEnd, size, m);

    // to check
    BFS(root);

    return 0;
}

// Note - here there were no duplicate values
// But if there are duplicates make function that return index of inorder[i]
//  and mark that visited to it dont return that again
// question on gfg - https://www.geeksforgeeks.org/problems/construct-tree-1/1
// like -
// int pos(int in[],int num, int n){
//     for(int i = 0 ; i < n; i++){
//         if(in[i] == num && in[i] >=0){
//             in[i] = -1;
//             return i;
//         }
//     }
//     return -1;
// }

// Or create map<int,deque<int>> to store index and m[inorder[i]].pop_front() after use
// void createMap(int in[],int n, unordered_map<int,deque<int>> &m){
//     for(int i = 0 ; i < n; i++){
//         m[in[i]].push_back(i);
//     }
// }

// find its position in Inorder and remove used one
// deque<int> v = m[root -> data];
// int position = v.front();
// m[root->data].pop_front();