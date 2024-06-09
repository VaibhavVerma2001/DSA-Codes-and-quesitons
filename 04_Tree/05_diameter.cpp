/*
https://leetcode.com/problems/diameter-of-binary-tree/description/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1

*/


// Logic -
// We need to find 2 nodes X and Y such that their distance is max
// option1 - both present in left subtree
// option2 - both present in right subtree
// option3 - 1 present in left subtree,1 in right subtree (height left) + height(right)
// return max of them
// tc = O(N*N), means brute force because calculating height of each node

// Condition - Take & of them
    // 1 - left subtree balanced
    // 2 - right subtree balanced
    // 3 - L.H - R.H <= 1

    // BC = when root is NULL return true
    // TC = O(N*N), because calculating height for each node

    // int height(TreeNode *root)
    // {
    //     if (root == NULL)
    //     {
    //         return 0;
    //     }

    //     int l = 1 + height(root->left);
    //     int r = 1 + height(root->right);
    //     return max(l, r);
    // }

    // bool isBalanced(TreeNode* root) {
    //     if(root == NULL){
    //         return true;
    //     }

    //     int leftheight = height(root->left);
    //     int rightheight = height(root->right);

    //     if(abs(leftheight - rightheight ) > 1){
    //         return false;
    //     }

    //     bool leftAns = isBalanced(root->left);
    //     bool rightAns = isBalanced(root->right);
        
    //     return (leftAns && rightAns);
        
    // }


    // Method 2 - faster way TC = O(N)
    // keep track while calculating height

    int height(TreeNode *root, bool &ans)
    {
        if (root == NULL)
        {
            return 0;
        }

        int l = height(root->left,ans);
        int r = height(root->right,ans);

        // find if not balanced
        if(abs(l-r) > 1){
            ans = false;
        }
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        bool ans = true;
        height(root,ans);
        return ans;
    }