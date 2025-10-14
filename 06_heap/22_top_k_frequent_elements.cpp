/*
https://leetcode.com/problems/top-k-frequent-elements/description/

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]

 

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

*/

class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> m;
    //     vector<int> ans;
    //     for(auto x : nums){
    //         m[x]++;
    //     }

    //     // run loop k times and find max freq and then element to corresponding freq 
    //     while(k--){
    //         int freq = 0 , ele = 0;
    //         for(auto x : m){
    //             if(x.second != -1){ // if -1 means it has been added already
    //                 if(x.second >= freq){
    //                     freq = max(freq,x.second);
    //                     ele = x.first;
    //                 }
    //             }
    //         }

    //         ans.push_back(ele);
    //         // then erase that element from map , so that it dont come together
    //         m[ele] = -1; 
    //     }


    //     return ans;
    // }


    // Logic - using min-heap <freq. num>, store k largest freq

    struct Compare{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.first > b.first; // min-heap
        }
    };

    vector<int> topKFrequent(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare > pq;
        for(int &x : arr){ // O(N)
            m[x]++;
        }

        for(auto &x : m){ // O(N LOG K)
            pair<int,int> p = {x.second, x.first}; // <freq,num>
            if(pq.size() < k || x.second > pq.top().first){
                pq.push(p);
                if(pq.size() > k){
                    pq.pop();
                }
            }
            
        }

        vector<int> ans;
        while(!pq.empty()){ // O(K LOG K)
            pair<int,int> p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }

        return ans;
    }
};
// TC = O(N LOG N)