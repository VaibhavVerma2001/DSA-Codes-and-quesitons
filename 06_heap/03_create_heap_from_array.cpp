// TC for creating heap from array of size is O(N), not O(n log n)
// Given an array of n elements. The task is to build a Max Heap from the given array.
// Input: arr[] = {4, 10, 3, 5, 1}
// Output: Corresponding Max-Heap:

//        10
//      /   \
//    5     3
//   /  \
// 4    1

// Input: arr[] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17}
// Output: Corresponding Max-Heap:

//                  17
//               /      \
//           15         13
//          /    \      /  \
//        9      6    5   10
//      / \    /  \
//    4   8  3    1


// Logic - heapify code of deletion 
// Run for all non-leaf nodes bottom to top (n/2 - 1 to 0th index), bec leaf node is already valid heap 

#include<iostream>
using namespace std;


void heapifyRec(int *arr, int n, int index){
    if (index >= n){
        return ;
    }

    int largestIndex = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if(left < n && arr[left] > arr[largestIndex]){
        largestIndex = left;
    }
    if(right < n && arr[right] > arr[largestIndex]){
        largestIndex = right;
    }

    if(largestIndex == index){
        return ;
    } else {
        swap(arr[index], arr[largestIndex]);
        heapifyRec(arr,n,largestIndex);
    }
}

void heapify(int *arr, int n, int index){
    while(index < n){
        int largestIndex = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if(left < n && arr[left] > arr[largestIndex]){
            largestIndex = left;
        }
        if(right < n && arr[right] > arr[largestIndex]){
            largestIndex = right;
        }

        if(largestIndex == index){
            break;
        } else {
            swap(arr[index], arr[largestIndex]);
            index = largestIndex;
        }
    }
}

void buildHeap(int *arr, int n){
    for(int i = n/2 -1 ; i >=0 ; i--){
        // heapify(arr, n, i);
        heapifyRec(arr, n, i );
    }
}


void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    int arr[5] = {4, 10, 3, 5, 1};
    buildHeap(arr, 5);
    printArray(arr, 5);

    int arr2[11] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    buildHeap(arr2, 11);
    printArray(arr2, 11);
    return 0;
}