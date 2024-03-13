#include <bits/stdc++.h> 
using namespace std;

void quickSort(vector<int> &arr, int s , int e){
    // BC
    if(s>=e){
        return ;
    }

    int i = s-1, j = s, pivot = e;

    while(j < pivot){
        if(arr[j] < arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }

    // when partition done
    i++; // now i is right place of pivot
    swap(arr[i],arr[pivot]);


    // RC
    quickSort(arr,s,i-1);
    quickSort(arr,i+1,e);
}


int main ()
{
    vector<int> arr = {11,13,12,1,2,5,3};
    int s = 0 , e = arr.size()-1;
    quickSort(arr,s,e);

    cout<<"After swapping \n";
    for(auto &x : arr){
        cout<<x<<" ";
    }
    return 0 ;
}