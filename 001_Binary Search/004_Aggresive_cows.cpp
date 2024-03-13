// https://www.geeksforgeeks.org/problems/aggressive-cows/1

bool isPossible(vector<int> &arr, int n, int k, int mid)
{
    int cow = 1;      // count of cow
    int pos = arr[0]; // position of last cow placed, place 1st cow at 0th index

    // can we place k cows with atleast mid distance between them?
    for (int i = 1; i < n; i++)
    {
        int diff = arr[i] - pos;
        if (diff < mid)
        {
            continue;
        }
        else
        {
            // place that cow at this position
            pos = arr[i];
            cow++;

            // if all cows placed
            if (cow == k)
            {
                return true;
            }
        }
    }
    return false;
}

int solve(int n, int k, vector<int> &arr)
{

    // Write your code here

    // Sort array
    sort(arr.begin(), arr.end());

    int s = 0, e = arr[n - 1] - arr[0], ans = -1, mid;

    while (s <= e)
    {
        mid = s + (e - s) / 2;

        if (isPossible(arr, n, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return ans;
}