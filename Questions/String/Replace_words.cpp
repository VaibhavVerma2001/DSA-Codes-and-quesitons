/*
https://leetcode.com/problems/replace-words/description/

In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

 

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
 

Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.

*/


class Solution {
public:
    // Logic -
    // store root in set
    // traverse each word in sentence character by charater if at some time it is found in set then replace that word with that root
    string replaceWords(vector<string>& dict, string str) {
        unordered_set<string> s;
        string ans;

        for(auto &x : dict){
            s.insert(x);
        }

        int i = 0 , n = str.length();
        while(i < n){
            string temp, root;
            int j = i;
            bool found = false;
            while(j < n && str[j] != ' '){
                temp.push_back(str[j]);
                // we need only first root 
                if(!found && s.find(temp) != s.end()){
                    root = temp;
                    found = true;
                }
                j++;
            }

            if(found){
                ans = ans + root + " ";
                i = j+1;
            }
            else{
                ans = ans + str.substr(i,(j-i)) + " ";
                i = j+1;
            }
            
        }

        if(ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};