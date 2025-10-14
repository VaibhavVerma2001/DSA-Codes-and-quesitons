/*
https://leetcode.com/problems/task-scheduler/description/

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:
Input: tasks = ["A","C","A","B","D","B"], n = 1
Output: 6
Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:
Input: tasks = ["A","A","A", "B","B","B"], n = 3
Output: 10
Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.
There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

 

Constraints:
1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100
*/


class Solution {
public:

    // Count freq of each task in a map.
    // Push all freq into a max heap.
    // While heap not empty:
    //   Pop up to (n + 1) tasks → decrement count → store in temp.
    //   Push back remaining (non-zero) counts to heap.
    //   If heap empty → time += temp.size(), else time += n + 1.
    // Return total time.
    // TC: O(T log 26) ≈ O(T) SC: O(26)

    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        
        // Store freq
        unordered_map<char,int> freq;
        for(char ch : tasks){
            freq[ch]++;
        }

        // Push freq in map heap
        priority_queue<int> pq;
        for(auto &x : freq){
            pq.push(x.second);
        }

        // Consume n + 1 tasks with max freq (n + 1 because we need to wait n time after consuming 1 element) till heap not empty
        while(!pq.empty()){
            vector<int> temp; // to store freq

            // pop n+1 elements
            for(int i = 0 ; i < n + 1; i++){
                if(!pq.empty()){
                    int top = pq.top();
                    pq.pop();
                    top--;
                    temp.push_back(top);
                }
            }
        
            // push left elements again to queue
            for(auto &x : temp){
                if(x > 0) {
                    pq.push(x);
                }
            }

            

            // if we always add  n + 1 to time, even when the heap is empty after the last round — causing extra idle time counted unnecessarily.
            if(pq.empty()){
                time += temp.size();
            } else {
                time += n + 1;
            }
        }

        return time;

    }
};