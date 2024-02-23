
// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include<iostream>
#include<vector>
using namespace std ;



void merge(vector<int> &arr,vector<int> &temp, int s , int e , int mid, int &cnt){

    // Now merge 2 sorted arrays
    // left array s-> mid , right array mid + 1 -> e
    int i = s , j = mid + 1;
    int index = s; // main array index

    while(i <= mid && j <= e){
        if(arr[i] <= arr[j]){
            temp[index] = arr[i];
            index++, i++;
        }
        else{
            temp[index] = arr[j];
            index++, j++;

            // ONLY CHANGE HERE TO COUNT PAIRS when arr[i] > arr[j]
            cnt = cnt + (mid - i + 1);
        }
    }

    while(i <= mid){
        temp[index] = arr[i];
        index++, i++;
    }

    while(j <= e){
        temp[index] = arr[j];
        index++,j++;
    }
    
    // change actual values
    while(s<=e){
        arr[s] = temp[s];
        s++;
    }
}


void mergeSort(vector<int> &arr,vector<int> &temp, int s , int e, int &cnt){
    
    // BC 
    if(s>=e){
        return ;
    }
    
    int mid = s + (e-s)/2;
    
    // left array
    mergeSort(arr,temp,s,mid,cnt);
    
    // right array
    mergeSort(arr,temp,mid +1 ,e,cnt);
    
    // merge logic
    merge(arr,temp, s,e,mid,cnt);
    
    
}



long countInversions(vector<int> arr) {
    // Merge Sort - TC = O(N* log(n)), SC = O(log n)
    
    int s = 0 , e = arr.size()-1;
    vector<int> temp (arr.size(), 0);
    int cnt = 0;
    // or we can make cnt as global variable, instead of passing as arguement
    mergeSort(arr,temp,s,e,cnt);
    return cnt;
    
}

int main ()
{
    vector<int> arr = {8,4,2,1};
    cout<<countInversions(arr)<<endl;

    arr = {1,5,3,7};
    cout<<countInversions(arr)<<endl;

    arr = {2,4,1,3,5};
    cout<<countInversions(arr)<<endl;

    arr = {2,3,4,5,6};
    cout<<countInversions(arr)<<endl;

    arr = {10,10,10};
    cout<<countInversions(arr)<<endl;
    return 0 ;
}