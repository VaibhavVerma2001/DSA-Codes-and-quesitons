/*
https://leetcode.com/problems/path-sum-iii/submissions/1282701995/

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3


*/


class Solution {
public:
    // Logic - Like subarray sum equal to K
    // keep on storing psum in map and check if psum - target exists in map for some node
    // TC = SC = O(N)

    // // Without BT
    // void solve(TreeNode *root, int target, unordered_map<long long,int> m, long long pSum, int &ans){
    //     if(root == NULL){
    //         return ;
    //     }

    //     // x + target = psum ==> x = psum - target
    //     pSum += root -> val;

    //     if(m.find((pSum - target)) != m.end()){
    //         ans = ans + m[(pSum - target)];
    //     }
    //     m[pSum]++;

    //     solve(root -> left, target, m, pSum, ans);
    //     solve(root -> right, target, m, pSum, ans);
    // }


    // With BT -> faster
    void solve(TreeNode *root, int target, unordered_map<long long,int> &m, long long &pSum, int &ans){
        if(root == NULL){
            return ;
        }

        // x + target = psum ==> x = psum - target
        pSum += root -> val;

        if(m.find((pSum - target)) != m.end()){
            ans = ans + m[(pSum - target)];
        }
        m[pSum]++;

        solve(root -> left, target, m, pSum, ans);
        solve(root -> right, target, m, pSum, ans);

        //BT
        m[pSum]--;
        pSum -= root -> val;
    }


    int pathSum(TreeNode* root, int target) {
        int ans = 0;
        long long pSum = 0;
        unordered_map<long long,int> m;
        m[0] = 1; // when root can also be included then psum - target = 0, so there should be 0 in map
        solve(root, target, m, pSum, ans);
        return ans;
    }
};