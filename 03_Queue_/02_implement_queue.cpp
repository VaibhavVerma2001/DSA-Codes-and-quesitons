#include<iostream>
using namespace std ;

class queue{
    public :

    int *arr;
    int front;
    int rear;
    int size;


    queue(int size){
        this -> size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void push(int x){
        if(rear == size -1){
            cout<<"queue overflow"<<endl;
        }

        // handle 1st case when queue is empty
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = x;
        }

        // Normal case
        else{
            rear++;
            arr[rear] = x;
        }
    }

    void pop(){
        // if queue is empty
        if(front == -1 && rear == -1){
            cout<<"Queue Underflow" <<endl;
        }
        // when there is only 1 element -> reset queue
        if(front == rear){
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }
        // Normal case
        else{
            arr[front] = -1;
            front++;
        }
    }

    int getSize(){
        if(front == -1 && rear == -1){
            return 0;
        }
        else{
            return (rear - front + 1);
        }
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    int getFront(){
        if(front == -1 && rear == -1){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getRear(){
        if(front == -1 && rear == -1){
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    void print (){
        cout<<"Printing queue : ";
        for(int i = 0 ; i < size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};




int main (){

    queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);

    q.print();

    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.isEmpty()<<endl;

    cout<<"After popping 1 element"<<endl;
    q.pop();
    q.print();
    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;

    cout<<"After popping all elements"<<endl;
    q.pop();
    q.pop();

    cout<<q.getSize()<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<q.isEmpty()<<endl;

    q.print();
   
    return 0 ;
}