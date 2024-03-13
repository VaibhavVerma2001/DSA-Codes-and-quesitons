// eg st1 = {43,37,25,47,33,10} , n = 6 , OP = 25  -> n/2 
//          top    mid     last

// eg st1 = {70, 50, 30, 20, 10} , n = 5 , OP = 10  -> (n+1)/2
//          top      mid     last


#include<iostream>
#include<stack>
using namespace std ;

// dont take n as ref bec it should be different for each call
void getMiddle(stack<int> &st, int i, int mid){
    // BC
    if(i == mid){
        cout<<"Middle element for i : "<<i<<" is : "<<st.top()<<endl;
        return ;
    }

    // solve 1 case
    int temp = st.top();
    st.pop();

    // RC 
    getMiddle(st,i+1, mid);

    //BT -> put elements again 
    st.push(temp);
}


// if we take by reference "&" , it empty stack
void print(stack<int> st){
    cout<<"Printing values : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main (){
    stack<int> st;
    st.push(10); // n = 6
    st.push(20);
    st.push(30);
    st.push(40); // mid
    st.push(50);
    st.push(60); // n = 1


    int n = st.size(), i = 1, mid;
    if(n % 2 == 0){
        mid = n/2;
    }
    else{
        mid = (n+1)/2;
    }
    getMiddle(st,i,mid);


    return 0 ;
}