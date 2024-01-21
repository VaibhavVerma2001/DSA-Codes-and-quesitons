// https://leetcode.com/problems/house-robber/description/ 

class Solution {
public:
    // DP QUESTION - SO TLE WITH RECURSION 
    int solve(vector<int> &nums, int i , int n){
        // BC
        if(i>=n){
            return 0;
        }

        // chori kari at ith index
        int option1 = nums[i] + solve(nums,i+2,n); // can't stole at i+1 index

        // chori nhi kari
        int option2 = solve(nums,i+1,n);

        int finalAns = max(option1,option2);
        return finalAns;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = solve(nums,i,n);
        return ans;
    }
};