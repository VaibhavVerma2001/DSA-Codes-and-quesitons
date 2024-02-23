// https://leetcode.com/problems/group-anagrams/description/

class Solution {
public:
    // Conclusion 1: 2 anagrams will have the same sorted string.
    // Conclusion 2: Unique anagrams will have Unique sorted strings.

    // Time complexity: O(n* m*log(m))
    // Total space complexity is O(N * K).  
    // n is the size of size of vector
    // m is the length of individual strings
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(int i = 0 ; i < strs.size(); i++){
            // do not change actual values,so that later on we can push that
            string str = strs[i];
            sort(str.begin(),str.end());
            m[str].push_back(strs[i]);
        }

        cout<<endl;

        vector<vector<string>> ans;

        for(auto &x : m){
            vector<string> temp;
            for(auto &y : x.second){
                temp.push_back(y);
            }
            ans.push_back(temp);
        }
        return ans;
    }



    // Method 2 - since hash[256] of tea, ate, eat is same so we can make hash as key and string vector as pair
    // No need of sorting now
    // TC = O(n * m)
    // SC = O(n * m)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> m;

        for(int i = 0 ; i < strs.size(); i++){
            vector<int> hash(256,0);
            for(int j = 0 ; j < strs[i].size(); j++){
                hash[strs[i][j]]++;
            }
            m[hash].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto &x : m){
            vector<string> temp;
            for(auto &y : x.second){
                temp.push_back(y);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};