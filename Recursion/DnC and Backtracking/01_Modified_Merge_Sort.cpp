#include <iostream>
#include <vector>
using namespace std;

// Initially we needed to create left and right array each time in merging logic, it waste so much extra time, so we can create 1 temp array of same size and merge in that only, instead of creating left and right array each time


// TC AND SC Same as older one but little bit better

void merge(vector<int> &v, vector<int> &temp, int start, int mid, int end)
{
    int i = start, j = mid + 1;
    // first array = start -> mid
    // second array = mid + 1 -> end
    // merged array => start -> end
    int k = start;

    while (i <= mid && j <= end)
    {
        if (v[i] <= v[j]){
            temp[k++] = v[i++];
        }
        else{
            temp[k++] = v[j++];
        }
    }

    // handle remaining elements in case of diff array size
    while (i <= mid){
        temp[k++] = v[i++];
    }

    while (j <= end){
        temp[k++] = v[j++];
    }

    // let's copy merged data
    while (start <= end)
    {
        v[start] = temp[start];
        start++;
    }
}

void mergeSort(vector<int> &v, vector<int> &temp, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    // divide
    mergeSort(v, temp, start, mid);
    mergeSort(v, temp, mid + 1, end);

    // conqour
    merge(v, temp, start, mid, end);
}

int main ()
{
    vector<int> arr =  {2,9,6,1,4,3};
    vector<int> temp (arr.size() , 0);
    int s = 0 , e = 5;
    mergeSort(arr,temp,s,e);

    cout<<"After sorting"<<endl;

    for(int i = 0 ; i< 6; i++){
        cout<<arr[i]<<" ";
    }
    return 0 ;
}
