// https : // www.geeksforgeeks.org/problems/next-larger-element-1587115620/1


// TC = SC = O(N)
#include <bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here

    stack<long long> st;
    st.push(-1);

    vector<long long> ans(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() <= arr[i] && st.top() != -1)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }

    return ans;
}

int main()
{
    vector<long long> arr = {6,8,0,1,3};
    vector<long long> ans = nextLargerElement(arr, 5);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}


// For prev greater elememt -> run loop from i = 0 to n-1