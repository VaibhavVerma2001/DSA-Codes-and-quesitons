// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

//  since in BST inorder traversal is in sorted order, so use that
    // void inorder(TreeNode* root, vector<int> &v){
    //     if(root == NULL){
    //         return ;
    //     }

    //     // left call
    //     inorder(root -> left, v);

    //     v.push_back(root -> val);

    //     // right call
    //     inorder(root -> right, v);
    // }

    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> v;
    //     inorder(root, v);

    //     return v[k-1];
    // }



    // Method 2 -> Keep count of inorder traversal instead of storing in vector
    void inorder(TreeNode* root, int &k, int &ans){
        if(root == NULL){
            return ;
        }

        // left call
        inorder(root -> left, k, ans);

        k--;
        if(k == 0){
            ans = root -> val;
            return ; // no need to proceed further
        }

        // right call
        inorder(root -> right, k, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);

        return ans;
    }