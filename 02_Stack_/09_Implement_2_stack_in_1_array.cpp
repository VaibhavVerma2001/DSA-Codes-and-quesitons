// https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1

// Method 1 -
// if size of array is n
// then 1st stack starts from top1 = -1 to n/2 and 2nd array top2 = n/2 to size
// But the problem is if 1st half is full and 2nd half has some space then still we can't insert in that


// Method 2 - 
// if size of array is n
// then 1st stack starts from top2 = -1 2nd array top2 = size
// overflow condiiton => top2-top1 == 1
// underflow for st1 = top == -1
// underflow for st2 = top == size


#include<iostream>
using namespace std ;


class Stack {

    public :
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int x){
        if(top2 - top1 == 1){
            cout<<"Stack 1 overflow"<<endl;
            return ;
        }

        top1++;
        arr[top1] = x;
    }

    void push2(int x){
        if(top2 - top1 == 1){
            cout<<"Stack 2 overflow"<<endl;
            return ;
        }

        top2--;
        arr[top2] = x;
    }

    int pop1(){
        if(top1 == -1){
            cout<<"Stack 1 underflow"<<endl;
            return -1;
        }
        int num = arr[top1];
        top1--;
        return num;
    }

    int pop2(){
        if(top2 == size){
            cout<<"Stack 2 underflow"<<endl;
            return -1;
        }
        int num = arr[top2];
        top2++;
        return num;
    }

    void print(){
        cout<<"Stack 1 : ";
        for(int i = top1 ; i >= 0 ; i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        cout<<"Stack 2 : ";
        for(int i = top2 ; i < size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};




int main ()
{
    Stack st(6);

    st.push1(10);
    st.push1(20);

    st.push2(30);
    st.push2(40);

    st.print();

    return 0 ;
}