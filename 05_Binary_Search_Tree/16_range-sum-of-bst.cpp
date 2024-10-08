/*
https://leetcode.com/problems/range-sum-of-bst/description/

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].



Example 1:
Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.


Example 2:
Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23
Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.


Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
*/

// Method 1 - traverse all nodes like binary tree -> TC = O(N)
// void solve(TreeNode* root, int low, int high, int &ans){
//     if(root == NULL){
//         return ;
//     }

//     if(root -> val >= low && root -> val <= high){
//         ans += root -> val;
//     }

//     solve(root -> left, low, high, ans);
//     solve(root -> right, low, high, ans);
// }



// Method 2 - use property of BST -> TC = O(height)
void solve(TreeNode *root, int low, int high, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    // case 1 - when root lies between range
    if (root->val >= low && root->val <= high)
    {
        ans += root->val;

        // then call for left and right
        solve(root->left, low, high, ans);
        solve(root->right, low, high, ans);
    }

    // Case 2 - when root is < low, means we can neglect left part
    else if (root->val < low)
    {
        solve(root->right, low, high, ans);
    }

    // Case 3 - when root is > low, means we can neglect right part
    else
    {
        solve(root->left, low, high, ans);
    }
}

int rangeSumBST(TreeNode *root, int low, int high)
{
    int ans = 0;
    solve(root, low, high, ans);
    return ans;
}