// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1

// eg st1 = {43,37,25,47,33,10} , n = 6 , OP = 25  -> n/2
//          top    mid     last

// eg st1 = {70, 50, 30, 20, 10} , n = 5 , OP = 10  -> (n+1)/2
//          top      mid     last

#include <iostream>
#include <stack>
using namespace std;

// dont take n as ref bec it should be different for each call
void insertAtBottom(stack<int> &st, int x)
{   
    // BC
    if (st.empty())
    {
        st.push(x);
        return;
    }

    // solve 1 case
    int temp = st.top();
    st.pop();

    insertAtBottom(st, x);

    // BT -> insert elements again
    st.push(temp);
}

// if we take by reference "&" , it empty stack
void print(stack<int> st)
{
    cout << "Printing values : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    print(st);

    insertAtBottom(st,400);
    print(st);


    return 0;
}