// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/


class Solution {
public:
    int minSteps(string s, string t) {
        // Loop over all characters if the frequency of a character in t is less than the frequency of the same character in s then add the difference between the frequencies to the answer.

        int ans = 0 ;
        unordered_map<int,int> m_s, m_t;

        for(int i = 0 ; i < s.length(); i++){
            m_s[s[i]]++;
            m_t[t[i]]++;
        }

        // loop is m_s not on m_t bec there might be characters which are not there in string s, so we need to add 1 more condition for that also
        for(auto &x : m_s){
            int freq = x.second;
            if(freq > m_t[x.first]){
                ans = ans +  freq - m_t[x.first];
            }
        }

        return ans;
    }
};