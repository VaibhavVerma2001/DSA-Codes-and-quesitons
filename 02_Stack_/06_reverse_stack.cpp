// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1


// logic - pop all elements till st is not empty
// then as a Backtracking -> Insert at Bottom

#include <iostream>
#include <stack>
using namespace std;

// TC = O(N) , SC = O(N)
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

// TC = O(N*N) , SC = O(N)
void reverse(stack <int> &st){
    // BC
    if(st.empty()){
        return;
    }

    // solve 1 case
    int temp = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st,temp);
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
    st.push(40);

    print(st);

    reverse(st);

    print(st);

    return 0;
}