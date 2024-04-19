/*
Question - https://leetcode.com/problems/valid-parenthesis-string/description/
Video Solution - https://www.youtube.com/watch?v=Pno2hATcwHA

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "(*)"
Output: true
Example 3:

Input: s = "(*))"
Output: true


Constraints:

1 <= s.length <= 100
s[i] is '(', ')' or '*'.

*/

// Method 1 - Recursion -> since we have options for * -> so try all that
// Recursion -> TC = O(3^N)
// bool solve(string &s , int open, int i){
//     // BC
//     if(i == s.length() && open == 0){
//         return true;
//     }

//     if(i == s.length() && open != 0){
//         return false;
//     }

//     // solve 1 case
//     bool isValid = false;

//     // 3 options when *
//     if (s[i] == '*'){
//         // treat as (
//         isValid |= solve(s,open+1,i+1);

//         // treat as ""
//         isValid |= solve(s,open,i+1);

//         // treat as ) // go next if open > 0 , otherwise wrong ans -> eg dry run s =")("
//         // bec if open < 0 means string is invalid
//         if(open > 0){
//             isValid |= solve(s,open-1,i+1);
//         }
//     }
//     else if(s[i] == '('){
//         isValid |= solve(s,open+1,i+1);
//     }
//     // go next if open > 0 , otherwise wrong ans -> eg dry run s =")("
//     // bec if open < 0 means string is invalid
//     else if(s[i] == ')' && open > 0){
//         isValid |= solve(s,open-1,i+1);
//     }

//     return isValid;
// }

// bool checkValidString(string s) {
//     int open = 0 , i = 0;
//     return solve(s,open,i);
// }



// Method 2 - Stack TC = O(N), SC = O(N)
// Make 2 int stack to store indices of "(" and "*"
// If ) comes and there is no star and ( in stack then return false
// to manage extra ( , eg - "*(())(*" -> at last in st1 5 is left and in st2 0,6 left, means 6 will manage out ( at 5th index

bool checkValidString(string s)
{
    stack<int> st, stars;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == '*')
        {
            stars.push(i);
        }
        else if (s[i] == ')')
        {
            if (st.empty() && stars.empty())
            {
                return false;
            }
            // use one (
            else if (!st.empty())
            {
                st.pop();
            }
            // use one *
            else
            {
                stars.pop();
            }
        }
    }

    // at last manage extra ( left
    while (!st.empty())
    {
        if (!stars.empty() && stars.top() > st.top())
        {
            st.pop();
            stars.pop();
        }
        else
        {
            break;
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}