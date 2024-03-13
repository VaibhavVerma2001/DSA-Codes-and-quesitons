// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include<iostream>
using namespace std ;

int knapsack(int profit[], int weight[] , int W,int i, int n){

    // BC -> when we traversed complete array or our bag capacity becomes 0
    if(i>=n || W == 0){
        return 0;
    }


    // Choice 1- when weight[i] > W, means we can't take that
    if(weight[i] > W){
        return knapsack(profit, weight,W,i+1, n);
    } 

    // Choice 2 - when weight[i] <= W we have 2 choices, either include or exclude
    int include = profit[i] + knapsack(profit,weight, W- weight[i],i+1, n);

    int exclude = 0 + knapsack(profit, weight, W, i+1, n);

    int ans = max(include,exclude);
    return ans;
}

int main ()
{
    int profit[] = { 60, 100, 120 }; 
    int weight[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = 3; 
    int i = 0;
    cout<<knapsack(profit,weight,W,i,n);

    return 0 ;
}