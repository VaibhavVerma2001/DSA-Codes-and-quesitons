// ip -> st = {10,20,30,40,50} , x = 25
// op -> st = {10,20,25,30,40,50}

#include <iostream>
#include <stack>
using namespace std;

// TC = O(N) , SC = O(N)
void insertSorted(stack<int> &st, int x){
    if(st.empty() || x > st.top() ){
        st.push(x);
        return ;
    }

    int temp = st.top();
    st.pop();


    insertSorted(st,x);

    // BT
    st.push(temp);
}

// if we take by reference "&" , it empty stack
void print(stack<int> st){
    cout << "Printing values : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    print(st);

    insertSorted(st,65);
    insertSorted(st,25);
    insertSorted(st,5);

    print(st);

    return 0;
}