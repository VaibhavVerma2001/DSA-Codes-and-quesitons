/*
https://leetcode.com/problems/find-bottom-left-tree-value/description/

Given the root of a binary tree, return the leftmost value in the last row of the tree.

 

Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/



class Solution {
public:
    // Method 1- 
    // store the ans if it is leaf along with its level and if another leaf found with bigger level then update
    
    // void dfs(TreeNode *root , int &ans, int &ansLvl, int lvl){
    //     if(root == NULL){
    //         return;
    //     }

    //     if(root->left == NULL && root -> right == NULL){
    //         if(lvl > ansLvl ){
    //             ans = root->val;
    //             ansLvl = lvl;
    //         }
    //     }

    //     dfs(root -> left ,ans, ansLvl, lvl + 1);
    //     dfs(root -> right ,ans, ansLvl, lvl + 1);
    // }
    // int findBottomLeftValue(TreeNode* root) {
    //     int lvl = 0, ansLvl = -1, ans = -1;
    //     dfs(root,ans,ansLvl,lvl);
    //     return ans;
    // }


    // Method 2 - left most view of binary tree
    // level order traversal -> left most element of last level
    // void solve(TreeNode *root, int lvl,int &ans, int &cnt){
    //     if(root == NULL){
    //         return ;
    //     }
        
    //     // if(ans.size() == lvl){
    //     //     ans.push_back(root->val);
    //     // } // instead of vector using cnt to count level
    //     if(cnt == lvl){
    //         ans = root -> val;
    //         cnt++;
    //     }

        
    //     solve(root->left,lvl + 1,ans,cnt);
    //     solve(root->right,lvl + 1,ans,cnt);
    // }
    // int findBottomLeftValue(TreeNode* root) {
    //     int ans;
    //     int lvl = 0,cnt = 0;
    //     solve(root,lvl,ans,cnt);
    //     return ans;
    // }


    // Method 3 - level order traversal -> left most element of last view
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL){
            return -1;
        }

        int ans = -1;
        queue<TreeNode *> q;
        // Initial state
        q.push(root);
        q.push(NULL);
        ans = root -> val;

        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();

            if(front == NULL){

                if(q.size()>0){
                    // means not at front there is left most child of next lvl
                    TreeNode *lchild = q.front();
                    ans = lchild -> val;
                    q.push(NULL);
                }
            }
            else{
                if(front -> left){
                    q.push(front->left);
                }
                if(front -> right){
                    q.push(front -> right);
                }
            }
        }
        return ans;
    }
};