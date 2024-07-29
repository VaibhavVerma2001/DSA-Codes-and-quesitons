/*

Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having maximum sum of nodes will be considered.

Example 1:

Input:
         4
       /   \
      2     5
     / \   / \
    7   1 2   3
       /
      6
Output:
13
Explanation:
         4
       /   \
      2     5
     / \   / \
    7   1 2   3
       /
      6
The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
Example 2:

Input:
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output:
11
Explanation:
Use path 1->3->7, with sum 11.
Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
0 <= data of each node <= 104

*/

void solve(Node *root, int currSum, int lvl, int &maxSum, int &maxH)
{
    // BC
    if (root == NULL)
    {
        return;
    }

    currSum += root->data;

    // for leaf node check max path and maxSum
    if (root->left == NULL && root->right == NULL)
    {
        if (lvl > maxH)
        {
            maxSum = currSum;
            maxH = lvl;
        }
        else if (lvl == maxH)
        {
            maxSum = max(maxSum, currSum);
        }
    }

    solve(root->left, currSum, lvl + 1, maxSum, maxH);
    solve(root->right, currSum, lvl + 1, maxSum, maxH);
}

int sumOfLongRootToLeafPath(Node *root)
{
    // code here
    int maxSum = 0, currSum, lvl = 0, maxH = 0;
    solve(root, currSum, lvl, maxSum, maxH);
    return maxSum;
}