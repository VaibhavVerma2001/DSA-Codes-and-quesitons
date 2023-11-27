// Question - https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/
// Solution - https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/solutions/4326214/simple-easy-solution-with-comments/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Logic - 
    // total time = total no. of M, P , G + time to reach last house where there is P,G,M

    int garbageCollection(vector<string>& g, vector<int>& t) {
        int total = 0, last_G = 0 , last_P = 0, last_M = 0;

        for(int i = 0 ; i < g.size(); i++){
            for(int j = 0 ; j < g[i].length(); j++){
                if(g[i][j] == 'G'){
                    last_G = i;
                }
                else if(g[i][j] == 'P'){
                    last_P = i;
                }
                else{
                    last_M = i;
                }
                total++; // 1 minute for each M,P,G
            }
        }

        // Prefix sum
        for(int i = 1 ; i < t.size(); i++){
            t[i] = t[i] + t[i-1];
        }

        // time for each of them to reach ith home
        if(last_G != 0){
            total = total + t[last_G - 1];
        }
        
        if(last_P != 0){
            total = total + t[last_P - 1];
        }

        if(last_M != 0){
            total = total + t[last_M - 1];
        }

        return total;
    }
};