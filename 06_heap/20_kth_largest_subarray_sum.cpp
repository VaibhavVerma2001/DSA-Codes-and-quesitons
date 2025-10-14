/*
https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

Given an array arr[] of size n, find the sum of the K-th largest sum among all contiguous subarrays. In other words, identify the K-th largest sum from all possible subarrays and return it.

Examples:

Input: arr[] = [3, 2, 1], k = 2 
Output: 5
Explanation: The different subarray sums we can get from the array are = [6, 5, 3, 2, 1]. Where 5 is the 2nd largest.
Input: arr[] = [2, 6, 4, 1], k = 3
Output: 11
Explanation: The different subarray sums we can get from the arrayare = [13, 12, 11, 10, 8, 6, 5, 4, 2, 1]. Where 11 is the 3rd largest.
Constraints:
1 <= arr.size() <= 1000
1 <= k <= (n*(n+1))/2
-105 <= arr[i] <= 105
*/


class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int,vector<int>, greater<int>> pq; // min-heap
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){ // O(N)
            int currSum = 0;
            for(int j = i; j < n; j++){ // O(N)
                currSum += arr[j];
                if(pq.size() < k ){
                    pq.push(currSum); // O(log k)
                } else {
                    if(currSum > pq.top()){
                        pq.pop(); // O(log k)
                        pq.push(currSum); // O(log k)
                    }
                }
            }
        }
        return pq.top();
    }
    
    // TC = O(N * N log (k))
    // TC = (k)
};