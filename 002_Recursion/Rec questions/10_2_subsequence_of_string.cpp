// Q - Given a string, find all its subsequences
// IP 1 -> str = "abc"
// OP -> ["a" , "b" , "c" , "ab" , "bc" ,"ac" , "abc", ""] -> 8 subseq.
// therefore total subseq. = 2 ^ n


//Method 1 -  INCLUDE - EXCLUDE PATTERN TC = O(2^n)
// At each index we have 2 choices, either include that character or exclude that

#include<iostream>
#include<string>
#include <cmath>
using namespace std ;


// Method 2 - Bit manipulation
// str = "abc" -> total subseq = 2 ^ n = 8  (in bits 0 to 7)
// 0 -> 000  -> ""
// 1 -> 001  -> "c"
// 2 -> 010  -> "b"
// 3 -> 011  -> "bc"
// 4 -> 100  -> "a"
// 5 -> 101  -> "ac"
// 6 -> 110  -> "ab"
// 7 -> 111  -> "abc"

void findSubSeq(string str){
    int n = str.length();
    int total_sub = pow(2,n);

    // for each subsequence convert to binary and take if bit is 1
    for(int num = 0; num < total_sub; num++){
        string temp;
        // check bit
        for(int i = 0; i < 32; i++ ){ // or i < n bec in bits it will be atmost of n number of bits
            if ( (num&(1<<i)) != 0){
                temp.push_back(str[i]);
            }
        }

        // print subseq.
        cout<<temp<<endl;
    }
}



int main ()
{
    string str = "abc";
    findSubSeq(str);
    return 0 ;
}

