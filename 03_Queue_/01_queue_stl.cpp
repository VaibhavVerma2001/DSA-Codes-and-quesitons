#include<iostream>
#include<queue>
using namespace std ;

void print(queue<int> q){
    cout<<"Printing queue elements : ";
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main ()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    print(q);
    cout<<"size of queue is "<<q.size()<<endl;
    cout<<"Front element is "<<q.front()<<endl;
    cout<<"Last element is "<<q.back()<<endl;


    q.pop();
    
    print(q);
    cout<<"size of queue is "<<q.size()<<endl;
    cout<<"Front element is "<<q.front()<<endl;
    cout<<"Last element is "<<q.back()<<endl;

    return 0 ;
}