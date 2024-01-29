// https://www.hackerrank.com/challenges/anagram/problem

#include<bits/stdc++.h>
using namespace std;


int anagram(string s) {
    int n = s.length();
    
    // if not possible to break in 2 equal parts
    if(n&1){
        return -1;
    }
    
    int ans = 0;
    unordered_map<char,int> m;
    
    for(int i = 0; i <n/2; i++){
        m[s[i]]++;
    }
    
    for(int i = n/2; i< n; i++){
        m[s[i]]--;
    }
    
    for(auto &x :m){
        if(x.second != 0){
            ans = ans +abs( x.second);
        }
    }
    
    return ans/2;
}

int main(){
    string s = "abccde";
    cout<<anagram(s)<<endl;
    return 0;
}