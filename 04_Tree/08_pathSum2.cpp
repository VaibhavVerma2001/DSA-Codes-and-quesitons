/*
https://leetcode.com/problems/path-sum-ii/

Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.



Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
*/

// Logic -
// Keep track of current sum of each node,and path till that node
// if current node is leaf and sum = target sum -> save that
void solve(TreeNode *root, int targetSum, int currSum, vector<int> &curr, vector<vector<int>> &ans)
{

    // BC
    if (root == NULL)
    {
        return;
    }

    // Extra 1 case
    curr.push_back(root->val);
    currSum += root->val;

    if (root->left == NULL && root->right == NULL && (currSum == targetSum))
    {
        ans.push_back(curr);
    }

    solve(root->left, targetSum, currSum, curr, ans);
    solve(root->right, targetSum, currSum, curr, ans);

    // BT - do when taking curr vector by reference
    curr.pop_back();
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> curr;
    solve(root, targetSum, 0, curr, ans);
    return ans;
}