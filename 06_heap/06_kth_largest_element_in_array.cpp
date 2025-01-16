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
int findKthLargest(vector<int> &nums, int k){
    // create min heap, so that largest element remain at bottom
    priority_queue<int, vector<int>, greater<int> > pq;
    for (auto &x : nums) {
        pq.push(x);
        // remove extra element
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}


// Similary more optimized, no need to insert again and again bec it will take time in heapify
// 1 - insert k elements
// 2 - now in min heap for largest element, insert only when element > pq.top(), bec if element < pq.top() then we are still going to remove it bec size becomes > k, and on top that element will be there

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;
    // insert k elements
    for(int i = 0 ; i < k; i++){
        pq.push(nums[i]);
    }
    // insert other elements only when element > pq.top()
    for(int i = k; i < nums.size(); i++){
        if(nums[i] > pq.top()){
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}



// For kth smallest element, use max-heap
