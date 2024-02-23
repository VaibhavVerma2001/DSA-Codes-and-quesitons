#include <iostream>
#include <vector>
using namespace std;

// TC for this merge code is O(N* Log(N)) , but SC is O(1)
// method 2 - Gap method -  SC = O(1) -> dont need extra space TC = O((n+m)*log(n+m))
// int gap = ceil (float(m)+n)/2 or gap = (m+n)/2 + ((m+n) % 2)
// i = 0 , j = i + gap
// if arr[i] > arr[j] => swap (arr[i], arr[j])
// i++, j++
// update gap = ceil(float(gap)/2)
// when gap 1 then do same but after that gap = ceil(0+1)/2 = 1 again so break now and array is sorted

// For merge function ONLY
// TC = O(N* log(N)) but SC = O(1)
// Time Complexity: O((n)*log(n)), where n and m are the sizes of the given arrays.
// Reason: The gap is ranging from n+m to 1 and every time the gap gets divided by 2. So, the time complexity of the outer loop will be O(log(n)). Now, for each value of the gap, the inner loop can at most run for (n) times. So, the time complexity of the inner loop will be O(n). So, the overall time complexity will be O((n)*log(n)).

// Space Complexity: O(1) as we are not using any extra space.

void merge(vector<int> &v, int s, int mid, int e)
{
    int len = e - s + 1;
    int gap = (len / 2) + (len % 2); // ceil

    while (gap >= 1)
    {
        int i = s, j = s + gap;
        while (j <= e)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
            i++, j++;
        }

        if (gap == 1)
        {
            break;
        }

        // update gap
        gap = (gap / 2) + (gap % 2); // ceil
    }
}

void mergeSort(vector<int> &v, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    // divide
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);

    // conqour
    merge(v, start, mid, end);
}

int main()
{
    vector<int> arr = {2, 9, 6, 1, 4, 3};
    int s = 0, e = 5;
    mergeSort(arr, s, e);

    cout << "After sorting" << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
