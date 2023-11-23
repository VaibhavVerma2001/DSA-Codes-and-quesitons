#include<iostream>
using namespace std ;

class stack{
    
    public : 
    int *arr;
    int top;
    int size;

    stack(int size){
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }

    void push(int val){
        if(top >= size-1){
            cout<<"Stack overflow"<<endl;
        }
        else{
            top++;
            arr[top] = val;
        }
    }

    bool empty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    void print(){
        cout<<"Stack values are : ";
        int n = top;
        while(n >= 0){
            cout<<arr[n]<<" ";
            n--;
        }
        cout<<endl;
    }

    int pop(){
        if(top == -1){
            cout<<"Stack already empty"<<endl;
            return -1;
        }
        else{
            int x = arr[top];
            top--;
            return x;
        }   
    }

    int topEle(){
        if(top == -1){
            cout<<"Stack empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }

    int getSize(){
        return top+1;
    }

};

int main ()
{
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<"Stack top is : "<<st.topEle()<<endl;
    cout<<"Stack size is : "<<st.getSize()<<endl;
    st.print();
    cout<<st.pop()<<endl;
    st.push(4);
    st.push(5);
    st.print();
    cout<<"Stack top is : "<<st.topEle()<<endl;
    cout<<"Stack size is : "<<st.getSize()<<endl;
    return 0 ;
}