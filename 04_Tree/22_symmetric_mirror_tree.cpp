/*
https://leetcode.com/problems/symmetric-tree/description/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false

*/

// TC = SC = 0(N) -> same as identical tree -> just compare p-> left with q -> right and vice versa

bool solve(TreeNode *p, TreeNode *q)
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

    // RC -> for p-> left check q-> right and for p -> right check q -> left
    bool leftAns = solve(p->left, q->right);
    bool rightAns = solve(p->right, q->left);

    return leftAns && rightAns;
}

bool isSymmetric(TreeNode *root)
{
    bool ans = solve(root->left, root->right);
    return ans;
}