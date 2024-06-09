/*
You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

 

Example 1:

Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].
Example 2:

Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

 

Constraints:

n == score.length
1 <= n <= 104
0 <= score[i] <= 106
All the values in score are unique.
*/



class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp = score;
        unordered_map<int,string> m;
        sort(temp.begin(),temp.end(),greater<int>());

        // store ranks in map
        for(int i = 0 ; i < temp.size(); i++){
            if(i+1 > 3){
                m[temp[i]] = to_string(i+1);
            }
            else if(i+1 == 1){
                m[temp[i]] = "Gold Medal";
            }
            else if(i+1 == 2){
                m[temp[i]] = "Silver Medal";
            }
            else{
                m[temp[i]] = "Bronze Medal";
            }
        }

        // now check rank from map in original array
        vector<string> ans;

        for(auto &x : score){
            ans.push_back(m[x]);
        }
        
        return ans;
    }
};


// using vector of pairs
// class Solution {
// public:
//     vector<string> findRelativeRanks(vector<int>& score) {
//         int n = score.size();
//         vector<pair<int, int>> rem;
//         vector<string> res(n);
//         // store value with there index
//         for(int i = 0;i < n;i++)
//             rem.push_back({score[i], i});
//         // will sort based on pair.first means score
//         sort(rem.begin(), rem.end());
//         for(int i = n-1;i >= 0;i--){
//             if(i == n-1)res[rem[i].second] = "Gold Medal";
//             else if(i == n-2)res[rem[i].second] = "Silver Medal";
//             else if(i == n-3)res[rem[i].second] = "Bronze Medal";
//             else res[rem[i].second] = to_string(n-i);
//         }
//         return res;
//     }
// };