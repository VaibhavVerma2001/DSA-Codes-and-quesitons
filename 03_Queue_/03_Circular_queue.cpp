#include<iostream>
using namespace std ;

class Cqueue{
    public :
    int *arr;
    int size;
    int front;
    int rear;


    Cqueue(int size){
        this -> size = size;
        arr = new int [size];
        front = -1;
        rear = -1;
    }

    void push(int x){
        //1- overflow
        if((front == 0 && rear == size -1) || (rear == front -1)){
            cout<<"Stack Overflow"<<endl;
        }

        //2- Empty case
        else if(front == -1 && rear == -1){
            front++, rear++;
            arr[rear] = x;
        }

        //3- Circular condition
        else if(rear == size -1 && front != 0){
            rear = 0;
            arr[rear] = x;
        }

        //4- Normal case
        else{
            rear++;
            arr[rear] = x;
        }
    }

    void pop(){
        //1- underflow
        if(front == -1 && rear == -1){
            cout<<"Stack Underflow"<<endl;
        }

        //2- Single element case
        else if(front == rear){
            arr[front] = -1;
            front = -1, rear = -1;
        }

        //3- Circular condition
        else if(front == size -1){
            arr[front] = -1;
            front = 0;
        }

        //4- Normal case
        else{
            arr[front] = -1;
            front++;
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

    Cqueue cq(5);

    cq.print();

    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);

    cq.print();

    cq.pop();
    cq.pop();

    cq.print();

    cq.push(60);
    cq.push(70);
    cq.push(80);

    cq.print();

    return 0 ;
}