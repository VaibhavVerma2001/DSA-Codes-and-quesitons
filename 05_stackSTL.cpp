#include<iostream>
#include<stack>
using namespace std ;

int main ()
{
    stack<int> st;

    // insert - at last
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // size
    cout<<"size is : "<<st.size()<<endl;

    // remove - last element
    st.pop();

    cout<<"size is : "<<st.size()<<endl;

    // print
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    cout<<"size is : "<<st.size()<<endl;


    return 0 ;
}