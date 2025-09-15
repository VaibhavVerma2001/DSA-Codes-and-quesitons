// Logic - 
// Step 1 - build heap
// Step 2 - Insert at last (swap root and last) -> now ignore last element and consider it sorted bec root was max
// Step 3 - heapify root (top to bottom)

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

void heapSort(int *arr, int n){
    // Step 1 - build heap
    buildHeap(arr, n);

    while(n){
        // Step 2 - swap root and last element
        swap(arr[0], arr[n-1]);

        // consider last element deleted
        n--;

        // Step 3 - heapify root
        heapifyRec(arr, n, 0);
    }
}




int main(){
    int arr[6] = { 5, 10, 15, 20, 25, 12};
    heapSort(arr, 6);
    printArray(arr,6);
    
    return 0;
}


// Time Complexity: O(n log n)
// Auxiliary Space: O(log n), due to the recursive call stack. However, auxiliary space can be O(1) for iterative implementation.