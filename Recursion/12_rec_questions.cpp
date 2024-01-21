#include<iostream>
using namespace std ;


// Q 1 - Find last occurance of char in a string
// IP 1 = str = "abcdefdgh", char = 'd' , OP = 6

// Method 1 -> search left to right and update ans
// TC - O(N), SC = O(N)
void lastOccurance1(string &str, char ch, int n , int i , int &ans){
    // BC
    if(i >= n){
        return;
    }

    // PROC.
    if(str[i] == ch){
        ans = i;
    }

    // RC
    lastOccurance1(str, ch,n,i+1,ans);
}


// Method 2 -> serach from right to left and stop after getting char
// TC - O(N), SC = O(N)
void lastOccurance2(string &str, char ch, int n, int i, int &ans){
    // BC
    if(i < 0){
        return;
    }

    // PROC.
    if(str[n-1] == ch){
        ans = n-1;
        return ; // break loop after 1st occurance
    }

    // RC
    lastOccurance2(str, ch,n,i-1, ans);
}



// Q2 - Reverse a string
// IP -> str = "abcdef" , OP = "fedcba"
// IP -> str = "abcdefg" , OP = "fgedcba"
// TC = O(N), SC = O(N)
void reverseString(string &str, int s , int e){ // pass str by reference
    // BC
    if(s >= e){
        return ;
    }

    // Proc.
    swap(str[s],str[e]);

    // RC
    reverseString(str,s+1,e-1);
}



// Q3 - Check palindrome string
// IP -> str = "racecar" , OP = true
// IP -> str = "racestar" , OP = false
// TC = O(N), SC = O(N)
bool cheeckPalindrome(string &str, int s , int e){ // pass str by reference
    // BC
    if(s >= e){
        return true;
    }

    // Proc.
    if(str[s] != str[e]){
        return false;
    }

    // RC
    bool ans = cheeckPalindrome(str,s+1,e-1);
    return ans;
}



int main ()
{
    // Q1 - Last occ. of char in string
    string str = "abcdefdgh";
    char ch = 'd';
    int n = str.length(), i = 0, ans = -1;
    lastOccurance1(str,ch,n,i,ans);
    cout<<ch<<" is found at rightmost index : "<<ans<<endl;

    lastOccurance2(str,ch,n,n-1,ans);
    cout<<ch<<" is found at rightmost index : "<<ans<<endl;


    // Q2 - Reverse a string
    str = "abcdefg";
    int s = 0, e = str.length()-1;
    reverseString(str,s,e);
    cout<<"After reversing , str becomes : "<<str<<endl;



    // Q3 - Check palindrome string
    str = "racecar";
    s = 0 , e = str.size()-1;
    if(cheeckPalindrome(str,s,e)){
        cout<<str<< " is plaindrone."<<endl;
    }
    else{
        cout<<str<<" is not palindrome."<<endl;
    }

    str = "racestar";
    s = 0 , e = str.size()-1;
    if(cheeckPalindrome(str,s,e)){
        cout<<str<< " is plaindrone."<<endl;
    }
    else{
        cout<<str<<" is not palindrome."<<endl;
    }

    
    return 0 ;
}