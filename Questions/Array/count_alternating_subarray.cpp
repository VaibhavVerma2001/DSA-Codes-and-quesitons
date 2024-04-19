/*

https://leetcode.com/problems/count-alternating-subarrays/

You are given a
binary array
 nums.

We call a
subarray
 alternating if no two adjacent elements in the subarray have the same value.

Return the number of alternating subarrays in nums.


Example 1:

Input: nums = [0,1,1,1]

Output: 5

Explanation:

The following subarrays are alternating: [0], [1], [1], [1], and [0,1].

Example 2:

Input: nums = [1,0,1,0]

Output: 10

Explanation:

Every subarray of the array is alternating. There are 10 possible subarrays that we can choose.

*/

#include<iostream>
#include<vector>
using namespace std ;

// long long countAlternatingSubarrays(vector<int>& arr) {
//     int i = 0 , j = 0, n = arr.size();
//     long long ans = 0;

//     while(j < n){
//         // check if j+1 < n, otherwise index out of bound here
//         if(j+1 < n && arr[j] != arr[j+1]){
//             j++;
//         }
//         // case of j == n-1 will be handeled here
//         else{
//             long long len = j - i + 1;
//             ans = ans + (len*(len+1))/2;
//             j++;
//             i = j;
//         }
//     }
//     return ans;
// }




// same logic using while loop
long long countAlternatingSubarrays(vector<int> &arr)
{
    int i = 0, j = 0, n = arr.size();
    long long ans = 0;

    while (j < n)
    {
        // check if j+1 < n, otherwise index out of bound here
        while (j + 1 < n && arr[j] != arr[j + 1])
        {
            j++;
        }
        long long len = j - i + 1;
        ans = ans + (len * (len + 1)) / 2;
        j++;
        i = j;
    }
    return ans;
}
