/*
https://leetcode.com/problems/increasing-order-search-tree/description/

Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

 

Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]
 

Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000

*/


// LOGIC -> make sorted array from inorder traversal
    // then traverse array and keep on creating new node to its left
    // TC = SC = O(N)

    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL){
            return ;
        }

        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }

    TreeNode* solve(vector<int> &v , int index){
        if(index >= v.size()){
            return NULL;
        }

        TreeNode* root = new TreeNode(v[index]);

        root -> right = solve(v,index+1);

        return root;
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);

        return solve(v,0);
    }


    // method 2 -- better
    // void make(TreeNode* root, TreeNode*& ans){
    //     if(root == NULL) return;
    //     make(root->left, ans);
    //     // ans->left = NULL;
    //     ans->right = new TreeNode(root->val);
    //     ans = ans->right;
    //     make(root->right, ans);
    // }

    // TreeNode* increasingBST(TreeNode* root) {
    //     TreeNode* dummy = new TreeNode(-1);
    //     TreeNode* ans = dummy;
    //     make(root, ans);
    //     return dummy->right;
    // }