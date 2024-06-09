/*
https://leetcode.com/problems/find-common-characters/description/

Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.

 

Example 1:

Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: words = ["cool","lock","cook"]
Output: ["c","o"]
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.

*/

class Solution {
public:
    // logic - https://www.youtube.com/watch?v=0sMVPGsY84w
    // create a cnt array to count frequency (initially keep count of 1st word)
    // now iterate all words from i = 1 and store its freq in temp array
    // now check count and temp array and keep common char freq only in count array
    vector<string> commonChars(vector<string>& words) {
        int count[26] = {0};

        // initialise count with 1st word freq
        for(auto &x : words[0]){
            count[x - 'a']++;
        }

        // now iterate all words from i = 1 and store its freq in temp array
        for(int i = 1 ; i < words.size(); i++){
            string word = words[i];
            int temp[26] = {0};

            for(auto &x : word){
                temp[x - 'a']++;
            }


            // update count array
            for(int i = 0 ; i < 26; i++){
                count[i] = min(count[i],temp[i]);
            }
        }


        //store ans
        vector<string> ans;

        for(int i = 0 ; i < 26; i++){
            int freq = count[i];
            while(freq > 0){
                // https://stackoverflow.com/questions/18938740/c-convert-ascii-value-to-string-in
                string s;
                s =  char(i + 'a');
                ans.push_back(s);
                freq--;
            }
        }

        return ans;
    }
};