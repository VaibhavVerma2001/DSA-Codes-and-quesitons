// https://leetcode.com/problems/implement-stack-using-queues/description/

#include<bits/stdc++.h>
using namespace std;

// Method 1 - using 1 queue
// push at front of queue - TC = O(N)
// pop, top from front of queue - TC = O(1)

class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        // eq - q = [1,2,3,4], x = 5, op = [5,1,2,3,4]
        // therefore -> 
        // step 1 - q.push(x) -> q = [1,2,3,4,5]
        // step 2 - pop and push 4 elements (means initial size of queue)-> q = [5,1,2,3,4]

        int size = q.size();

        // step 1 -
        q.push(x);

        // step 2 -

        for(int i = 0 ; i< size; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        int temp = q.front();
        return temp;
    }
    
    bool empty() {
        return q.empty();
    }
};
