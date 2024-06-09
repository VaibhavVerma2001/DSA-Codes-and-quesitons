/*
https://leetcode.com/problems/same-tree/description/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false

*/

// TC = SC = 0(N)
bool isSameTree(TreeNode *p, TreeNode *q)
{
    // when both NULL
    if (p == NULL && q == NULL)
    {
        return true;
    }

    // when any of them is NULL
    if (p == NULL || q == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    // RC
    bool leftAns = isSameTree(p->left, q->left);
    bool rightAns = isSameTree(p->right, q->right);

    return leftAns && rightAns;
}