/*
// https://leetcode.com/problems/kth-largest-element-in-an-array/

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?



Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

// TC = O(n log n), SC = O(k)
int findKthLargest(vector<int> &nums, int k)
{
    // create min heap, so that largest element remain at bottom
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &x : nums)
    {
        pq.push(x);
        // remove extra element
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    return pq.top();
}

// For kth smallest element, use max-heap