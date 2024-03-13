// https://www.codingninjas.com/studio/problems/sort-a-stack_985275?leftPanelTabValue=PROBLEM
// Input: Stack: 11 2 32 3 41
// Output: 41 32 11 3 2


// Logic - pop till stack is empty , then insert in sorted order
// TC = O(N*N) , SC = O(N)

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

void sortStack(stack<int> &st){
    if(st.empty()){
        return ;
    }

    int temp = st.top();
    st.pop();

    sortStack(st);
    

    // BT -> insert at sorted pos
    insertSorted(st,temp);
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
    st.push(11);
    st.push(2);
    st.push(32);
    st.push(3);
    st.push(41);

    print(st);

    sortStack(st);

    print(st);

    return 0;
}