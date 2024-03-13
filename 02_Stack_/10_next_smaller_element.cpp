// https://www.codingninjas.com/studio/problems/next-smaller-element_1112581?leftPanelTabValue=PROBLEM



#include<bits/stdc++.h>
using namespace std;

// TC = SC = O(N)
vector<int> nextSmallerElement(int *arr, int n)
{
    stack<int> st;
    st.push(-1);

    vector<int> ans(n,0);

    for(int i = n-1; i >= 0 ; i--){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        // ans.push_back(st.top());
        ans[i] = st.top();
        st.push(arr[i]);
    }

    // reverse(ans.begin(), ans.end());

    return ans;

}


int main(){
    int arr[] = {8,4,6,2,3};
    vector<int> ans = nextSmallerElement(arr,5);
    for(auto x : ans){
        cout<<x<<" ";
    }

    return 0;
}




// For prev smaller elememt -> run loop from i = 0 to n-1