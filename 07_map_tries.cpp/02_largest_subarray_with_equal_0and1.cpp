/*
https://leetcode.com/problems/contiguous-array/description/


Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Example 3:

Input: nums = [0,1,1,1,1,1,0,0,0]
Output: 6
Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
 

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
*/



class Solution {
public:
    // Logic - convert 0 to -1 
    // now question become same as longest subarray with sum k (here k = 0)
    // https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809
    // TC = O(N), SC = O(1)
    
    int findMaxLength(vector<int>& arr) {
        int n = arr.size();  
        // for(int i = 0 ; i < n ; i++){
        //     if(arr[i] == 0){
        //         arr[i] = -1;
        //     }
        // }   // No need to convert, treat 0 as -1 during sum

        int ans = 0;
        unordered_map<int, int> m;
        m[0] = 0;  // prefix sum 0 occurs before any element (shifted logic)
        int psum = 0;

        for (int i = 0; i < n; i++) {
            // treat 0 as -1
            if(arr[i] == 0){
                psum += -1;
            } else {
                psum += arr[i];
            }

            if (m.find(psum) != m.end()) {
                int pos = m[psum];
                ans = max(ans, (i + 1 - pos)); // +1 because we stored shifted index
            }

            // store only first occurrence
            if (m.find(psum) == m.end()) {
                m[psum] = i + 1; // shifted index
            }
        }

        return ans;
    }
};