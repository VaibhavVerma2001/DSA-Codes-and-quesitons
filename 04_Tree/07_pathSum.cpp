/*
https://leetcode.com/problems/path-sum/description/
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:

Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

*/

// Logic -
// Keep track of current sum of each node
// if current node is leaf and sum = target sum -> return true
// take || OR of left subtree and right subtree
bool solve(TreeNode *root, int targetSum, int currSum)
{
    // BC - given in test case
    if (root == NULL)
    {
        return false;
    }

    currSum += root->val;

    if (root->left == NULL && root->right == NULL && currSum == targetSum)
    {
        return true;
    }

    bool leftAns = solve(root->left, targetSum, currSum);
    bool rightAns = solve(root->right, targetSum, currSum);

    return (leftAns || rightAns);
}
bool hasPathSum(TreeNode *root, int targetSum)
{
    return solve(root, targetSum, 0);
}