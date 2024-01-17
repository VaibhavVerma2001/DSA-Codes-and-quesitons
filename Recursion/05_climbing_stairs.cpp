// https://leetcode.com/problems/climbing-stairs/description/

#include <iostream>
using namespace std;

// TLE bec TC = O(2^n)
// similar to fib series
// int climbStairs(int n) {

//     if(n == 1 ){
//         return 1;
//     }
//     if(n == 2 ){
//         return 2;
//     }

//     int ans = climbStairs(n-1) + climbStairs(n-2);
//     return ans;
// }


// METHOD 2 - TC = O(N)
// Normal fic code, but here it starts with 1,2,3,5,....
int climbStairs(int n)
{

    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }

    // for n =1 , op = 1, n = 2, op = 2
    int a = 1, b = 2, c = a + b;

    for (int i = 3; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n = 5;
    cout<<climbStairs(n)<<endl;
    return 0;
}