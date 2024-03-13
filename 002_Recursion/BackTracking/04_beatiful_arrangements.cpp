// https://leetcode.com/problems/beautiful-arrangement/description/

#include<iostream>
#include<vector>
using namespace std;

// Method 1 - Find all permutations and check if it is beautiful
// TC = O(N* N!) , SC = O(N) -> for making vector of 1 to N
// But TLE
// bool isBeautiful(vector<int> & v){
//     for(int i = 0; i < v.size() ; i++){
//         if( ((v[i] % (i+1)) !=0 ) && ( ((i+1) % v[i])!= 0) ){
//             return false;
//         }
//     }
//     return true;
// }

// int countArrangement(int n) {
//     vector<int> v;
//     for(int i = 1 ; i <= n ; i++){
//         v.push_back(i);
//     }

//     int ans = 0;
//     // for 1st permutation
//     if(isBeautiful(v)){
//         ans++;
//     }

//     while(next_permutation(v.begin(),v.end())){
//         if(isBeautiful(v)){
//             ans++;
//         }
//     }
//     return ans;
// }


// METHOD 2 - Without TLE

// Logic -
// keep each element on eac index and check if we can keep that there
// create vector of size n + 1 bec of 1 based indexing
// if v[i] == 0 means that pos is empty and we can keep element there if givem 2 conditions meet
// Back Tracking - While returning when we dont have to keep element at that pos, remove it by doing v[i] = 0

// Complexity
// Time complexity: O(N!)
// The algorithm explores different permutations through backtracking.
// In the worst case, it explores all possible arrangements, leading to a time complexity of O(N!) where N is the input size.

// Space complexity:
// The space complexity is O(N) due to the auxiliary space used for the nums vector and the recursion stack.
// The recursion depth is at most N, where N is the input size.

void solve(vector<int> &v, int n, int currNum, int &ans)
{

    // BC
    // when we placed 1 -> n elemenets
    if (currNum == n + 1)
    {
        // for(int i = 1; i<=n ; i++) {
        //     cout << v[i] <<" ";
        // }
        // cout<<endl;
        ans++;
        return;
    }

    // solve 1 case
    for (int i = 1; i <= n; i++)
    {
        // if pos is empty and 2 conditions meet
        if (v[i] == 0 && (currNum % i == 0 || i % currNum == 0))
        {

            // place element
            v[i] = currNum;

            // RC for other elements
            solve(v, n, currNum + 1, ans);

            // BT - unplace element
            v[i] = 0;
        }
    }
}

int main(){
    int n = 3;
    vector<int> v(n + 1, 0);
    int ans = 0;
    int currNum = 1;
    solve(v, n, currNum, ans);
    cout<<ans <<endl;
    return 0;
}