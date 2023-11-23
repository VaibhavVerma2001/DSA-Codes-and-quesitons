// Leetcode Link - https://leetcode.com/problems/arithmetic-subarrays/description/

// My solution - https://leetcode.com/problems/arithmetic-subarrays/solutions/4321848/2-simple-and-easy-solutions-with-comments-beats-97/

// Reference - https://www.youtube.com/watch?v=ErHay1GfIqw

// **************************  CODE **************************

#include<bits/stdc++.h>
using namespace std;;

// Method 1 - TC = O(m * nlog(n)) , where m is number of queries
// SC = O(n)
vector<bool> checkArithmeticSubarrays(vector<int> &arr, vector<int> &l, vector<int> &r){

    vector<bool> ans;

    for (int i = 0; i < l.size(); i++)
    {

        int s = l[i], e = r[i];

        // Make vector from index l[i] to r[i]
        // sort it and check common diff for each i and i+1 th index element
        vector<int> v(arr.begin() + s, arr.begin() + e + 1);
        sort(v.begin(), v.end());

        int d = v[1] - v[0], flag = 1;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] - v[i - 1] != d)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ans.push_back(true);
        }
        else
        {
            ans.push_back(false);
        }
    }

    return ans;
}



// Method 2 - TC= O(m*n) , SC = O(n)
vector<bool> checkArithmeticSubarrays(vector<int> &arr, vector<int> &l, vector<int> &r){
    
    vector<bool> ans;

    for (int i = 0; i < l.size(); i++)
    {

        int s = l[i], e = r[i];
        int n = e - s + 1, a1 = INT_MAX, an = INT_MIN;
        unordered_map<int, int> m;

        for (int j = s; j <= e; j++)
        {
            a1 = min(a1, arr[j]);
            an = max(an, arr[j]);
            m[arr[j]]++;
        }

        // when not divisible then no commin diff, means not AP
        if ((an - a1) % (n - 1) != 0)
        {
            ans.push_back(false);
        }
        else
        {
            // bec an = a1 + (n-1)d
            int d = (an - a1) / (n - 1), flag = 1;

            // nth term = a1 + (n-1)*d
            // check a+d, a+2d, .... , a+(n-1)d {which is an}

            for (int i = 1; i <= n - 1; i++)
            {
                int val = a1 + i * d;
                if (m.find(val) == m.end())
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
    }

    return ans;
}