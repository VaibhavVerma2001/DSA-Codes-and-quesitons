#include<iostream>
#include<vector>
using namespace std ;

// step 1 - Divide array in 2 parts
// step 2 - sort left and right parts by rec
// step 3 - merge sorted array



// Mergge 2 sorted array
void mergeTwoSortedArray(vector<int> &arr,int s, int e){
    int mid = (s+e)/2;
    //Create left and right array

    // USING ARRAY IN HEAP
    // int leftSize = mid - s + 1;
    // int rightSize = e - mid;

    // int *left = new int[leftSize];
    // int *right = new int[rightSize];


    // // Copy values in left array
    // int k = s;
    // for(int i = 0 ; i < leftSize; i++){
    //     left[i] = arr[k];
    //     k++;
    // }


    // // copy values in right array
    // k = mid + 1;
    // for(int i = 0 ; i < rightSize; i++){
    //     right[i] = arr[k];
    //     k++;
    // }


    // USING VECTOR
    // left array is from s to mid index
    arr = {2,4,1,3,5};
    cout<<countInversions(arr)<<endl;

    // free heap memory
    // delete [] left;
    // delete [] right;
}


void mergeSort(vector<int> &arr, int s , int e){
    // BC
    if(s>=e){
        return ;
    }

    //Step 1 - Break array
    int mid = s + (e-s)/2;

    // left part -> s to mid
    // right part -> mid + 1 to e

    // Step 2
    // Sort left and right part with recursion

    // for left array
    mergeSort(arr,s,mid);

    // for right array
    mergeSort(arr,mid+1,e);


    // Step 3 - merge 2 sorted array
    mergeTwoSortedArray(arr,s,e);

}


int main ()
{
    vector<int> arr =  {2,9,6,1,4,3};
    int s = 0 , e = 5;
    mergeSort(arr,s,e);

    cout<<"After sorting"<<endl;

    for(int i = 0 ; i< 6; i++){
        cout<<arr[i]<<" ";
    }
    return 0 ;
}