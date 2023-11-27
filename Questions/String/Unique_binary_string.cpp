// Leetcode = 1980
// Question Link - https://leetcode.com/problems/find-unique-binary-string/description/


// Solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int decimal(string s){
        int deci = 0, n = s.length();

        for(int i = n-1 ; i>=0 ;i--){
            deci = deci + (s[i] - '0')*pow(2,(n-1-i));
        }
        return deci;
    }
    string findDifferentBinaryString(vector<string>& v) {
        
        // Method 1 - TC = O(N*N) (traversing vector, and converting to decimal)
        // covert to decimal and insert in map, then check which element in not there in map, convert that element to binary and return

        // unordered_set<int> s;
        // int n = v.size();
        // string ans;

        // for(int i = 0 ; i< n;i++){
        //     int deci = decimal(v[i]);
        //     s.insert(deci);
        // }

        // // for(int i = 0; i < pow(2,n); i++){
        // // iterate till n only bec 0 to n there will be n+1 numbers, so definitely 1 will be missing in vector of n elements
        // for(int i = 0; i <=n; i++){
        //     if(s.find(i) == s.end()){
        //         // convert decimal to binary string, 16 bec in constraint n is till 16
        //         ans = bitset<16>(i).to_string(); 
        //         // since in string there are 16 bits, but we need only n bits
        //         ans = ans.substr(ans.length()-n);
        //         break;
        //     }
        // }


        // return ans;





        // Method 2 - TC = O(n), SC = O(1)
        // traverse vector and check v[i][i], if 1 then ans[i] = 0 else ans[i] = 1, in this way ans string will be different from each


        string ans;

        for(int i = 0 ; i < v.size(); i++){
            if(v[i][i] == '0'){
                ans.push_back('1');
            }
            else{
                ans.push_back('0');
            }
        }
        return ans;
    }
};