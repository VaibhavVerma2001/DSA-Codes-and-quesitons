#include<iostream>
using namespace std;

// deletion of root from max heap

// Compare with largest child and replace if parent < child for max heap
void heapify(int *arr, int n){
    int index = 0;
    while(index < n){
        // find largest child
        int largest = index, left = 2*index + 1, right = 2*index + 2;
        if(left < n && arr[left] > arr[largest]){
            largest = left;
        } 
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // replace if needed
        if(index != largest){
            swap(arr[index], arr[largest]);
        } else {
            break;
        }
        index = largest;
    }
}


// Recursive heapify
void heapifyRec(int *arr, int n, int index){
    // BC
    if(index >= n){
        return ;
    }

    // find largest child
    int largest = index, left = 2*index + 1, right = 2*index + 2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    } 
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // replace if needed
    if(index == largest){
        return ;
    } 
    swap(arr[index], arr[largest]);
    heapifyRec(arr, n, largest);
}

void deleteRoot(int *arr, int &n){
    // step 1 - replace root with last element, bec no one depends on last element
    arr[0] = arr[n-1];

    // step 2 - decrease size by 1
    n = n-1;

    // step 3 - heapify
    // heapify(arr,n);
    heapifyRec(arr,n,0);
}



//TC FOR HEAPIFY = O(log n)


void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    // Array representation of Max-Heap
    //     10
    //    /   \
    //   5    3
    //  / \   /
    // 2   4  1
    int arr[] = { 10, 5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    deleteRoot(arr, n);
 
    printArray(arr, n);
}