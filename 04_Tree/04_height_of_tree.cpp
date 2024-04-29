/*
https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
*/

// Method 1 - Using BFS
// when found NULL increment count++, becase each NULL represent 1 level  or height


// Method 2 - Recursion
int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int l = 1 + maxDepth(root->left);
        int r = 1 + maxDepth(root->right);

        return max(l,r);
    }