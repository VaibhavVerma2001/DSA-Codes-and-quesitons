#include<bits/stdc++.h>
using namespace std ;


// Input:
// 1 2 3 4 5 , k = 3
// Output: 
// 3 2 1 4 5

// reverse first k elements
void reverseK(queue<int> &q , int k){
    // BC
    if(k == 0 || q.empty()){
        return ;
    }

    int temp = q.front();
    q.pop();

    reverseK(q, k-1);

    // BT
    q.push(temp);
}

// move first n - k elements to last
void solve(queue<int> &q,int k){
    reverseK(q,k); // it becomes -> 4 5 3 2 1
    // so now reverse starting n - k elemets
    int num = q.size() - k;
    while(num > 0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        num--;
    }
}

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}


// OR Method 2 - using stack
// Instead of wrting 2 functions use stack to push first k elements to it
// then push those k elements to queue again
// pop and push first n-k elements 

// void reverseQueueFirstKElements(int k, queue<int>& Queue)
// {
//     if (Queue.empty() == true || k > Queue.size())
//         return;
//     if (k <= 0)
//         return;
 
//     stack<int> Stack;
 
//     /* Push the first K elements
//        into a Stack*/
//     for (int i = 0; i < k; i++) {
//         Stack.push(Queue.front());
//         Queue.pop();
//     }
 
//     /* Enqueue the contents of stack
//        at the back of the queue*/
//     while (!Stack.empty()) {
//         Queue.push(Stack.top());
//         Stack.pop();
//     }
 
//     /* Remove the remaining elements and
//        enqueue them at the end of the Queue*/
//     for (int i = 0; i < Queue.size() - k; i++) {
//         Queue.push(Queue.front());
//         Queue.pop();
//     }
// }

int main (){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    print(q);

    int k = 3;

    solve(q,k);

    cout<<"After reverse"<<endl;
    print(q);

    return 0 ;
}