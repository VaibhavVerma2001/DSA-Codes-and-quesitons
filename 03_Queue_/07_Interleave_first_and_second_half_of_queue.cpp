// https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/

// https://www.codingninjas.com/studio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTabValue=PROBLEM

#include<iostream>
#include<queue>
using namespace std ;

void solve(queue <int> &q){
    queue<int> second;
    int n = q.size()/2;

    // put first half in second queue and 1st half remain in q
    for(int i = 0; i < n; i++){
        second.push(q.front());
        q.pop();
    }

    // now push 1 - 1 element in q from second and q , then pop from both
    for(int i = 0 ; i < n ; i++){
        q.push(second.front());
        q.push(q.front());

        q.pop();
        second.pop();
    } 
}


void print(queue<int> q){
    cout<<"Printing queue : ";
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl << endl;
}

int main (){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    solve(q);

    print(q);

    return 0 ;
}