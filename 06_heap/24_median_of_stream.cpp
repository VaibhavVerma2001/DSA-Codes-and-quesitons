/*
https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1
https://leetcode.com/problems/find-median-from-data-stream/description/

Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

Examples:

Input:  arr[] = [5, 15, 1, 3, 2, 8]
Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0] 
Explanation: 
After reading 1st element of stream – 5 -> median = 5.0
After reading 2nd element of stream – 5, 15 -> median = (5+15)/2 = 10.0 
After reading 3rd element of stream – 5, 15, 1 -> median = 5.0
After reading 4th element of stream – 5, 15, 1, 3 ->  median = (3+5)/2 = 4.0
After reading 5th element of stream – 5, 15, 1, 3, 2 -> median = 3.0
After reading 6th element of stream – 5, 15, 1, 3, 2, 8 ->  median = (3+5)/2 = 4.0
Input: arr[] = [2, 2, 2, 2]
Output: [2.0, 2.0, 2.0, 2.0]
Explanation: 
After reading 1st element of stream – 2 -> median = 2.0
After reading 2nd element of stream – 2, 2 -> median = (2+2)/2 = 2.0
After reading 3rd element of stream – 2, 2, 2 -> median = 2.0
After reading 4th element of stream – 2, 2, 2, 2 ->  median = (2+2)/2 = 2.0
Constraints:
1 <= arr.size() <= 105
1 <= x <= 106
*/

class Solution {
  public:
  
    // The median of an array occurs at the center of sorted array, so the idea is to store the current elements in two nearly equal parts. A max heap (left half) stores the smaller elements, ensuring the largest among them is at the top, while a min heap (right half) stores the larger elements, keeping the smallest at the top.

    // For each new element:
    // - It is first added to the max heap.
    // - The max heap's top element is moved to the min heap to maintain order.
    // - If the min heap has more elements than the max heap, its top element is moved back to ensure balance.

    // This keeps both halves nearly equal in size, differing by at most one element. If the heaps are balanced, the median is the average of their root values; otherwise, it is the root of the heap with more elements.

    // Time Complexity: O(n * log n), SC = O(n)
    
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> leftMaxHeap; // smaller half
        priority_queue<int, vector<int>, greater<int>> rightMinHeap; // larger half
        vector<double> ans;
        
        for(int i = 0 ; i < arr.size(); i++){
            int num = arr[i];
            // Step 1: Always push into left heap first
            if (leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
                leftMaxHeap.push(num);
            } else {
                rightMinHeap.push(num);
            }
    
            // Step 2: Balance both heaps (size difference should be at most 1)
            if (leftMaxHeap.size() > rightMinHeap.size() + 1) {
                rightMinHeap.push(leftMaxHeap.top());
                leftMaxHeap.pop();
            } else if (rightMinHeap.size() > leftMaxHeap.size()) {
                leftMaxHeap.push(rightMinHeap.top());
                rightMinHeap.pop();
            }
            
            
            // find median
            if (leftMaxHeap.size() == rightMinHeap.size()) {
                double median =  (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
                ans.push_back(median);
            } else {
                double median = leftMaxHeap.top(); // left will always have 1 extra if odd
                ans.push_back(median);
            }
        }
        return ans;
    }
};
