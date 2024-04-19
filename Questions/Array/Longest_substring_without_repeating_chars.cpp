/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

Given a string s, find the length of the longest
substring
 without repeating characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int lengthOfLongestSubstring(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }

    int i = 0, j = 0, ans = 1;
    int n = s.length();
    vector<int> freq(256, 0);
    while (j < n)
    {
        freq[s[j]]++;
        if (freq[s[j]] == 1)
        {
            ans = max(ans, (j - i + 1));
            j++;
        }
        else
        {
            while (freq[s[j]] > 1)
            {
                freq[s[i]]--;
                i++;
            }
            j++;
        }
    }
    return ans;
}

// method 2 - Like below question
// https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
// if(s.length()==0){
//     return 0;
// }
// int ans = -1;
//     unordered_map<char,int> m;
//     int i = 0 , j = 0, n = s.length();
//     while(j<n){
//         m[s[j]]++;
//         if(m.size() == (j-i+1)){
//             ans = max(ans,(j-i+1));
//             j++;
//         }
//         else{
//             while(m.size() < (j-i+1)){
//                 m[s[i]]--;
//                 if(m[s[i]] == 0){
//                     m.erase(s[i]);
//                 }
//                 i++;
//             }
//             j++;

//         }
//     }
//     return ans;
// }