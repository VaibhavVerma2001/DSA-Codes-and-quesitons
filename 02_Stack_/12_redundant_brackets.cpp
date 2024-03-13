// https://www.codingninjas.com/studio/problems/redundant-brackets_975473

#include <bits/stdc++.h> 
using namespace std;

// TC = SC = O(N)
bool findRedundantBrackets(string &str)
{
    // Write your code here.
    stack<char> st;

    for(char &ch : str){
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else if(ch == ')') {
            int op = false;

            while(st.top() != '('){
                op++;
                st.pop();
            }

            st.pop();

            if(op == 0){
                return true;
            }
        }
    }
    return false;
}


int main(){
    string str = "(a*b+(c/d))";
    cout<<findRedundantBrackets(str)<<endl;

    str = "((a/b))";
    cout<<findRedundantBrackets(str)<<endl;

    return 0;
}