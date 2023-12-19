// https://leetcode.com/problems/peak-index-in-a-mountain-array/description/

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int s = 0;
        int e = arr.size() - 1;
        int mid;
        while (s <= e)
        {
            mid = (s + e) / 2;

            // if peak element
            if ((arr[mid] > arr[mid + 1]) && (arr[mid] > arr[mid - 1]))
            {
                return mid;
            }

            // if mid is on left line of mountain
            else if (arr[mid] < arr[mid + 1])
            {
                s = mid + 1;
            }

            // if mid is right side
            else
            {
                e = mid - 1;
            }
        }
        return mid;
    }
};