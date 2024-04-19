/*
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/

Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"
Example 3:

Input: s = "))(("
Output: ""
Explanation: An empty string is also valid.
 

Constraints:

1 <= s.length <= 105
s[i] is either'(' , ')', or lowercase English letter.

*/


// video - https://www.youtube.com/watch?v=NNxaYz0nrk0

    // Method 1 - 
    // Logic - push all indexes of '(' in stack (bec if we store index only then we will be able to find which bracket we need to remove)
    // if ')' found and st is empty means that index is invalid so mark s[i] = '*'
    // if ')' and st in not empty means valid paran. so st.pop() index
    
    // now manage extra '(' , so traverse stack and mark left indexes and invalid
    // TC = O(N), SC = O(N)

    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.length();

        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(st.empty()){
                    s[i] = '*';
                }
                else{
                    st.pop();
                }
            }
        }

        // now manage '(' indexes left in stack which are invalid
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }

        string temp ;
        for(int i = 0 ; i < n; i++){
            if(s[i] != '*'){
                temp.push_back(s[i]);
            }
        }

        return temp;
    }


    // Method 2 - Break problem in 2 parts
    // 1- first manage extra close paran. "(()))" by keeping count of '('
    // when we get ) and open > 0 means valid, else invalid
    // manage this goind left to right

    // 1- first manage extra open paran. "((())" by keeping count of ')'
    // when we get ( and close > 0 means valid, else invalid
    // manage this goind right to left

    string minRemoveToMakeValid(string s) {
        
        int n = s.length();
        int open = 0;

        // manage extra ) first left to right
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                open++;
            }
            else if(s[i] == ')'){
                if(open > 0){
                    open--;
                }
                else{
                    s[i] = '*';
                }
            }
        }

        // manage extra ( now right to left
        int close = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            if(s[i] == ')'){
                close++;
            }
            else if(s[i] == '('){
                if(close > 0){
                    close--;
                }
                else{
                    s[i] = '*';
                }
            }
        }

        string temp ;
        for(int i = 0 ; i < n; i++){
            if(s[i] != '*'){
                temp.push_back(s[i]);
            }
        }

        return temp;
    }




    // Method 3 - similar to approach 2
    string minRemoveToMakeValid(string s) {
        int count = 0;
        // manage extra )
        for(int i = 0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                count--;
            }
            if(count<0){
                s.erase(i,1);
                i--;
                count++;
            }
        }

        // manage extra ( from right to left
        int j = s.size()-1;
        while(j>=0 && count>0){
            if(s[j]=='('){
                s.erase(j,1);
                count--;
            }
            j--;
        }
        return s;
    }