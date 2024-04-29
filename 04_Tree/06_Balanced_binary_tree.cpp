/*
https://leetcode.com/problems/balanced-binary-tree/description/


Given a binary tree, determine if it is
height-balanced
.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true


Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false


Example 3:
Input: root = []
Output: true

*/

// Condition - Take & of them
// 1 - left subtree balanced
// 2 - right subtree balanced
// 3 - L.H - R.H <= 1

// BC = when root is NULL return true
// TC = O(N*N), because calculating height for each node


// Can be done in O(N) in going top to up 

int height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int l = 1 + height(root->left);
    int r = 1 + height(root->right);
    return max(l, r);
}

bool isBalanced(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    if (abs(leftheight - rightheight) > 1)
    {
        return false;
    }

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    return (leftAns && rightAns);
}