// Question -https://leetcode.com/problems/count-beautiful-substrings-i/description/

// solution - https://leetcode.com/problems/count-beautiful-substrings-i/solutions/4335520/simple-easy-solution-beats-100/

// TC = O(N*N) (beats 100% leetode), SC = O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u'){
            return true;
        }
        return false;
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.length(), ans = 0;

        for(int i = 0 ; i < n ;i++){
            int con = 0 , vow = 0;
            for(int j = i ; j < n ; j++){
                // count vowel and consonants
                if(isVowel(s[j])){
                    vow++;
                }
                else{
                    con++;
                }

                // check those 2 conditions
                if(vow == con){
                    if( (vow * con) % k == 0 ){
                        ans++;
                    }
                }
            }
        }
        
        return ans;
    }
};