#include<bits/stdc++.h>
using namespace std ;

// Exponential search involves two steps:  

// 1 - Find range where element is present
// 2 - Do Binary Search in above found range.
// How to find the range where element may be present? 
// The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater. 
// Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)




// Time Complexity : O(Log n) 
// Auxiliary Space : The above implementation of Binary Search is recursive and requires O(Log n) space. With iterative Binary Search, we need only O(1) space.
// Applications of Exponential Search: 

// 1 - Exponential Binary Search is particularly useful for unbounded searches, where size of array is infinite.
// 2 - It works better than Binary Search for bounded arrays, and also when the element to be searched is closer to the first element.


int binarySearch(vector<int> &arr, int l , int h , int key){
    int mid;

    while(l<=h){
        mid = l + (h-l)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if (arr[mid] < key){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return -1;
}

int ExponetialSearch(vector<int> &arr,int key){

    // if present at 0th index
    if(arr[0] == key){
        return 0;
    }

    // else find part where it is present
    int i = 1, n = arr.size();
    while(i < n && arr[i] <= key){
        i= i*2;
    }

    // now this loop will break when arr[i] > key or i > n
    // if arr[i] > key means now key present between i/2 and ith index

    int pos = binarySearch(arr,i/2,min(i,n-1),key);
    return pos;
}

int main ()
{
    vector<int> arr = {3,4,5,6,11,13,14,15,56,70};
    cout<<ExponetialSearch(arr,13)<<endl;
    cout<<ExponetialSearch(arr,70)<<endl;
    cout<<ExponetialSearch(arr,40)<<endl;
    return 0 ;
}