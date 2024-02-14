// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Method 1 - make seperate array containing +ve and -ve integers
        // vector<int> pos , neg;

        // for(auto x : nums){
        //     if(x >= 0){
        //         pos.push_back(x);
        //     }
        //     else{
        //         neg.push_back(x);
        //     }
        // }

        // vector<int> ans;

        // for(int i = 0 ; i < pos.size(); i++){
        //     ans.push_back(pos[i]);
        //     ans.push_back(neg[i]);
        // }

        // return ans;


        // Method 2 - let i and j point to +ve and - ve element
        // vector<int> ans;
        // int n = nums.size(), i = 0 , j = 0;

        // while(i < n && j < n){
        //     // let i point to +ve element
        //     while(i < n && nums[i] < 0){
        //         i++;
        //     }

        //     // let j point to +ve element
        //     while(j < n && nums[j] > 0){
        //         j++;
        //     }

        //     // now store +ve and -ve element
        //     ans.push_back(nums[i]);
        //     ans.push_back(nums[j]);

        //     i++,j++;
        // }
        // return ans;


        // Method 2 - let i and j point to +ve and - ve element index in ans array
        // since +ve element will come at even index and -ve ele will come at -ve index only
        
        int n = nums.size(), Pi = 0 , Ni = 1; // +VE and -ve index
        vector<int> ans(n);

        for(int &x : nums){
            if(x > 0){
                ans[Pi] = x;
                Pi += 2;
            }
            else{
                ans[Ni] = x;
                Ni +=2;
            }
        }

        return ans;
    }
};