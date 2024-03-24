#include<iostream>
#include<queue>
#include<stack>
using namespace std ;

// Method 1 - using stack 
// TC = SC = O(N)
// void reverseQueue(queue<int> &q){
//     stack<int> st;
//     // store in stack
//     while(!q.empty()){
//         int fr = q.front();
//         st.push(fr);
//         q.pop();
//     }

//     // now store again in queue
//     while(!st.empty()){
//         q.push(st.top());
//         st.pop();
//     }
    
// }


// Method 2 - using recursion 
// TC = SC = O(N)
void reverseQueue(queue<int> &q){
    
    // BC
    if(q.empty()){
        return ;
    }

    int temp = q.front();
    q.pop();

    // RC
    reverseQueue(q);

    // BT
    q.push(temp);
    
}

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main (){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    print(q);

    reverseQueue(q);

    print(q);

    return 0 ;
}