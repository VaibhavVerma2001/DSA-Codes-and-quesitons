#include<iostream>
using namespace std;

// deletion of root from max heap

// Compare with largest child and replace if parent < child for max heap
void heapify(int *arr, int n){
    int index = 0;
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


// Recursive heapify
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

int deleteRoot(int *arr, int &n){
    int top = arr[0];
    arr[0] = arr[n-1];
    n--;

    // heapify(arr,n);
    int index = 0;
    heapifyRec(arr, n , index);
    return top;
}



//TC FOR HEAPIFY = O(log n)


void printArray(int arr[], int n){
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()   {
    // Array representation of Max-Heap
    //     10
    //    /   \
    //   5    3
    //  / \   /
    // 2   4  1
    int arr[] = { 10, 5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << deleteRoot(arr, n) << endl;
 
    printArray(arr, n);

    cout << deleteRoot(arr, n) << endl;
 
    printArray(arr, n);
}