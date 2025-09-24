/*

Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

Example 1:
Input  :
n = 4 m = 3
a[] = {10, 5, 6, 2},
b[] = {12, 7, 9}
Output :
{12, 10, 9, 2, 5, 7, 6}

*/

// [Naive Approach] Using Max Heap - O((N + M)*log(N + M)) Time and O(N + M) Space: -> create max heap and push in that by travsersing arrays
// [Expected Approach] Merge and Build Heap- O(N + M) Time and O(N + M) Space: heapify merged array

void heapify(vector<int> &arr, int index, int n){
    if (index >= n){
        return;
    }

    int largestIndex = index;
    int leftIndex = index * 2 + 1;
    int rightIndex = index * 2 + 2;

    if (leftIndex < n && arr[leftIndex] > arr[largestIndex]){
        largestIndex = leftIndex;
    }

    if (rightIndex < n && arr[rightIndex] > arr[largestIndex]){
        largestIndex = rightIndex;
    }

    if (largestIndex == index){
        return;
    }
    swap(arr[index], arr[largestIndex]);
    heapify(arr, largestIndex, n);
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m){
    // your code here
    vector<int> arr;
    for (auto &x : a){
        arr.push_back(x);
    }
    for (auto &x : b){
        arr.push_back(x);
    }

    for (int i = (m + n) / 2; i >= 0; i--){
        heapify(arr, i, arr.size());
    }
    return arr;
}

// Time Complexity: O(N + M)
// Auxiliary Space: O(N + M)