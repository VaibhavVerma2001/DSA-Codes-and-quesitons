// https://www.spoj.com/problems/PRATA/
// IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection and get P (P<=1000) pratas packed for the function. The stall has L cooks (L<=50) and each cook has a rank R (1<=R<=8). A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata) (For example if a cook is ranked 2, he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order done. Please write a program to help him out.

// Input
// The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.

// Output
// Print an integer which tells the number of minutes needed to get the order done.

// Example
// Input:
// 3
// 10
// 4 1 2 3 4
// 8
// 1 1
// 8
// 8 1 1 1 1 1 1 1 1

// Output:
// 12
// 36
// 1


#include<bits/stdc++.h>
using namespace std ;

bool isPossible(vector<int> &arr, int n, int p, int mid){
    int cnt = 0; // to count initial cooked parata
    for(int i = 0 ; i < n ; i++){
        int Rank = arr[i], j = 1;
        int totalTime = 0;

        while(true){
            if(totalTime + (Rank*j) <= mid){
                totalTime= totalTime +  (Rank*j);
                cnt++;
                j++; // increment j => R,2R,3R, ....
                if(cnt == p){
                    return true;
                }
            }
            else{
                break;
            }
        }
    }
    return false;

}

// arr has rank of n cooks, p represents number of parats
int solve(vector<int> &arr, int n, int p){
    int s = 0 , mid, ans;
    // max is when we give all parats to cook with max rank
    int highestRank = *max_element(arr.begin(),arr.end());
    // R + 2R + 3R+ .... PR = R(1+2+3+ ... P)
    int e = highestRank * ((p*(p+1))/2);

    while(s <= e){
        // mid represents if cooks can cook paratas in atmost mid mins
        int mid = s + (e-s)/2;

        if(isPossible(arr,n,p,mid)){
            ans = mid;
            // minimize time
            e = mid - 1; 
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}

int main ()
{   
    // int n = 4;
    // int p = 10;
    // vector<int> arr = {1,2,3,4};
    // cout<<solve(arr,n,p)<<endl;

    // n = 1, p = 8;
    // arr = {1};
    // cout<<solve(arr,n,p)<<endl;

    
    // n = 8, p = 8;
    // arr = {1,1,1,1,1,1,1,1};
    // cout<<solve(arr,n,p)<<endl;

    int t;
    cin>>t;

    while(t--){
        int p,n;
        cin>>p>>n;
        vector<int> arr;
        for(int i = 0 ; i < n; i++){
            long long x;
            cin>>x;
            arr.push_back(x);
        }
        cout<<solve(arr,n,p)<<endl;
    }
    

    return 0 ;
}