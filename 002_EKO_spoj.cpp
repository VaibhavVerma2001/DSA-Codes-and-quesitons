// https://www.spoj.com/problems/EKO/

// Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

// Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

// Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

// Input
// The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

// The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.

// Output
// The first and only line of output must contain the required height setting.

// Example
// Input:
// 4 7
// 20 15 10 17

// Output:
// 15
// Input:
// 5 20
// 4 42 40 26 46

// Output:
// 36

#include<bits/stdc++.h>
using namespace std ;

bool isPossible(vector<long long> &arr,long long m, long long mid){
    long long totalWood = 0;

    for(auto &x : arr){
        // we get wood if height of that tree > mid (blade height)
        if(x > mid){
            totalWood = totalWood + x - mid;
        }
    }

    // check if we sufficient wood
    if(totalWood >= m){
        return true;
    }
    return false;
}


long long solve(vector<long long> &arr, long long m){
    long long n = arr.size(), mid, ans;
    long long s = 0, e = *max_element(arr.begin(),arr.end());

    while(s <= e){
        mid = s + (e-s)/2;

        // we get sufficient wood, so try to minimize wastage by setting blade up
        if(isPossible(arr,m,mid)){
            ans = mid;
            s = mid + 1;
        }
        // we need to cut more wood, so set blade at lower height
        else{
            e = mid - 1;
        }
    }
    return ans;
}

int main ()
{
    vector<long long> arr = {20,15,10,17};
    long long m = 7;
    cout<<solve(arr,m)<<endl;

    arr = {4,42,40,26,46};
    m = 20;
    cout<<solve(arr,m)<<endl;

    // long long n,m;
    // cin>>n>>m;
    // vector<long long> arr;
    // while(n--){
    //     long long x;
    //     cin>>x;
    //     arr.push_back(x);
    // }
    // cout<<solve(arr,m)<<endl;

    return 0 ;
}