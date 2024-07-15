/*

You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.

 

Example 1:

Input: s = "(abcd)"
Output: "dcba"
Example 2:

Input: s = "(u(love)i)"
Output: "iloveu"
Explanation: The substring "love" is reversed first, then the whole string is reversed.
Example 3:

Input: s = "(ed(et(oc))el)"
Output: "leetcode"
Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
 

Constraints:

1 <= s.length <= 2000
s only contains lower case English characters and parentheses.
It is guaranteed that all parentheses are balanced.

*/


class Solution {
public:
    
    void reverse(string &s, int start, int end){
        while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    // Method 1 - Store indices of '('  in stack then when ')' come, pop from stack and reverse string from st.top() + 1 to i - 1;
    // then traverse string again to remove ( and )
    // TC = O(n*n) 

    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.length();

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int start = st.top();
                st.pop();
                reverse(s,start + 1, i-1);
            }
        }

        // remove ( and )
        string temp;

        for(auto &x : s){
            if(x != '(' && x != ')'){
                temp.push_back(x);
            }
        }

        return temp;
    }


    // Method 2 - Same logic as previous but we dont need to traverse string again to remove ( and )
    // here now push temp.length(), so that we can know how many indexed we have to skip for reversing
    // TC = O(n*n) 
    // string reverseParentheses(string s) {
    //     stack<int> st;
    //     string temp; 
    //     int n = s.length();
    //     int curr = 0;

    //     for(int i = 0 ; i < n ;i++){
    //         if(s[i] == '('){
    //             st.push(temp.length());
    //         }
    //         else if (s[i] == ')'){
    //             int top = st.top();
    //             st.pop();
    //             reverse(temp , top, temp.length()-1);
    //         }
    //         else{
    //             temp.push_back(s[i]);
    //         }
    //     }
    //     return temp;
    // }
};