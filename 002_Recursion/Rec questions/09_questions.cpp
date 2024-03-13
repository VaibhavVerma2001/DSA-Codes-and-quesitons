// Q - 1 Given an array, check if it is sorted in increasing order
// IP1 - arr = {10,20,30,40,50} , op = true
// IP2 - arr = {10,30,20,40,50} , op = false

#include<iostream>
using namespace std ;


bool checkSorted(int *a, int n, int i){
    // BC
    if(i >= n){
        return true;
    }

    // Processing
    if(a[i] < a[i-1]){
        return false;
    }

    // RC
    bool ans = checkSorted(a,n,i+1);
    return ans;
}


int main(){
    int arr[] = {10,20,30,40,50};
    cout<<checkSorted(arr,5,1)<<endl;

    int arr2[] = {10,30,20,40,50};
    cout<<checkSorted(arr2,5,1)<<endl;
}
