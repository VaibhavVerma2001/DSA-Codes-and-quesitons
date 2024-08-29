/*

https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/


Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

*/




// Method 1 - using map -> TC = SC = O(N)
    // bool solve(TreeNode* root, int k, unordered_set<int> &s){
    //     if(!root){
    //         return false;
    //     }

    //     if(s.find(k - root -> val) != s.end()){
    //         return true;
    //     }

    //     s.insert(root -> val);

    //     bool leftAns = solve(root -> left, k, s);
    //     bool rightAns = solve(root -> right, k, s);

    //     return leftAns || rightAns;
    // }

    // bool findTarget(TreeNode* root, int k) {
    //     unordered_set<int> s;
    //     return solve(root,k,s);
    // }



    // Method 2 - using 2 pointers -> TC = SC = O(N) -> SINCE IN BST Inorder is sorted to store that and apply 2 pointers
    void inorder(TreeNode* root, vector<int> &v){
        if(!root){
            return;
        }
        
        inorder(root -> left, v);

        v.push_back(root -> val);

        inorder(root -> right, v);

    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        inorder(root, v);

        int s = 0, e = v.size()-1;
        while(s < e){
            if(v[s] + v[e] == k){
                return true;
            }
            else if(v[s] + v[e] < k){
                s++;
            }
            else{
                e--;
            }
        }
        return false;
    }