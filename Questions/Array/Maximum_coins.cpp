// leetcode - 1561
// Link - https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/
// Solution - https://leetcode.com/problems/maximum-number-of-coins-you-can-get/solutions/4324530/simple-easy-cpp-solution-with-comments/

// TC = O(N log n)
// SC = O(1)


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& v) {
        // Logic -
        // sort and from end take 2nd last element, and give 1st (smallest) element to bob
        // take n/3 elements
        // 1 2 3 4 5 6 7 8 9 -> take 8 , 6 , 4
        // 1 2 2 4 7 8 -> take 7 , 2 

        int ans = 0 , n = v.size();
        sort(v.begin(),v.end());
        // take n/3 elements, starting from 2nd last
        int  num = n/3 , i = n-2;

        while(num--){
            ans = ans + v[i];
            i = i-2;
        }

        return ans;
    }
};
