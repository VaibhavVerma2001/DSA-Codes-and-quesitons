/*
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

*/

class Solution {
public:
    /* 
    Similar to Merge k sorted arrays/ lists
    Create a Min-Heap to store K elements, one from each array, and a variable minrange initialized to a maximum value and also keep a variable max to store the maximum integer.
    Initially put the first element from each list and store the maximum value in max.
    Repeat the following steps until at least one list exhausts : 
    - find the minimum value or min, use the top or root of the Min heap which is the minimum element.
    - Now update the minrange if the current (max-min) is less than minrange.
    - Remove the top or root element from the priority queue, insert the next element from the list containing the min element
    - Update the max with the new element inserted if the new element is greater than the previous max.
    
    O(row*col Log row) Time and O(row) Space
    */

    class Item{
        public:
        int value;
        int row;
        int col;
        
        Item(int value, int row, int col){
            this -> value = value;
            this -> row = row;
            this -> col = col;
        }

        ~Item(){}
    };
    
    struct Compare{
        bool operator()(Item *a , Item *b) {
            return a -> value > b -> value; // smaller element has higher priority // min heap
        }
    };

    vector<int> smallestRange(vector<vector<int>>& arr) {
        int minAns, maxAns, currMax = INT_MIN, lowestRange = INT_MAX;
        priority_queue<Item*, vector<Item*>, Compare> pq;

        // store 1st element
        for(int row = 0 ; row < arr.size(); row++){
            Item *temp = new Item(arr[row][0], row, 0);
            currMax = max(arr[row][0], currMax);
            pq.push(temp);
        }

        // loop this any of the array is not empty
        while(true){ // O(row * col))
            Item *top = pq.top();
            pq.pop();

            int value = top -> value;
            int row = top -> row;
            int col = top -> col;
            
            // Find mim range
            if(lowestRange > currMax - value){
                minAns = value;
                maxAns = currMax;
                lowestRange = maxAns - minAns;
            } else if ((lowestRange == currMax - value) &&( minAns > value)){
                minAns = value;
                maxAns = currMax;
                lowestRange = maxAns - minAns;
            }

            // Insert next element of that array if exists
            col++;
            if(col >= arr[row].size()){
                break;
            }

            Item *temp = new Item(arr[row][col], row, col);
            currMax = max(arr[row][col], currMax);
            pq.push(temp); // O(log row)

            delete top;
        }

        return {minAns, maxAns};
    }
};