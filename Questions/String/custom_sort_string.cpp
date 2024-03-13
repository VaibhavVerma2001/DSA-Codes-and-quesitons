// https://leetcode.com/problems/custom-sort-string/description/

// solution - https://leetcode.com/problems/custom-sort-string/solutions/4860710/2-simple-and-easy-solutions-beats-100/

class Solution {
public:
    // Logic - iterare order string and place all chars of s in same order
    // Using unordered map to store freq
    // string customSortString(string order, string s) {
    //     unordered_map<char,int> m;
    //     for(auto &x : s){
    //         m[x]++;
    //     }

    //     string ans;

    //     for(int i = 0 ; i < order.length(); i++){
    //         if(m.find(order[i]) != m.end()){
    //             int freq = m[order[i]];
    //             while(freq--){
    //                 ans.push_back(order[i]);
    //             }
    //             m.erase(order[i]);
    //         }
    //     }

    //     // push left chars
    //     for(auto &x : m){
    //         int freq = x.second;
    //         while(freq--){
    //             ans.push_back(x.first);
    //         }
    //     }
    //     return ans;
    // }


    // Using vector to store freq
    string customSortString(string order, string s) {
        vector<int> freq(26,0);
        for(auto &x : s){
            freq[x - 'a']++;
        }

        string ans;

        for(int i = 0 ; i < order.length(); i++){
            if(freq[order[i] - 'a'] > 0){
                int num = freq[order[i] - 'a'];
                while(num--){
                    ans.push_back(order[i]);
                }
                freq[order[i] - 'a'] = 0;
            }
        }

        // push left chars
        for(int i = 0 ; i < 26; i++){
            if(freq[i] > 0){
                while(freq[i]--){
                    ans.push_back(i + 'a');
                }
            }
        }
        return ans;
    }
};