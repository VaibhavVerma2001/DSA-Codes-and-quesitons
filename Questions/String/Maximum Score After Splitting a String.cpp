// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/

// Logic - count total 1 and 0 in string
// iterate string again and check zero and one till that index

// TC = O(N), SC = O(1)

#include<iostream>
using namespace std;

int maxScore(string s)
{
    int totalZero = 0, totalOne = 0, currZero = 0, currOne = 0, ans = 0;

    // count total 1 and 0's in string
    for (auto &x : s)
    {
        if (x == '0')
        {
            totalZero++;
        }
        else
        {
            totalOne++;
        }
    }

    // count max of ans
    int i = 0, n = s.length();

    while (i < n)
    {
        if (s[i] == '0')
        {
            currZero++;
        }
        else
        {
            currOne++;
        }

        // for test case like s = "00", op = 1, bec it cant be splitted in 2 parts when i = n-1 and ans = 2
        if (i != n - 1)
        {
            ans = max(ans, (currZero + totalOne - currOne));
        }

        i++;
    }

    return ans;
}