// https://leetcode.com/problems/sliding-window-maximum/

// logic - make a list to keep track of only useful elements
vector<int> maxSlidingWindow(vector<int> &arr, int k)
{
    int i = 0, j = 0, n = arr.size();
    vector<int> ans;
    list<int> li; // or deque

    while (j < n)
    {

        // If greater number encountered than pop them from list
        // this way at front always be max element
        while (li.size() > 0 && li.back() < arr[j])
        {
            li.pop_back();
        }

        // arr[j] could be ans for next window
        li.push_back(arr[j]);

        if ((j - i + 1) < k)
        {
            j++;
        }

        else if ((j - i + 1) == k)
        {
            // max element will be at front
            ans.push_back(li.front());

            // check of front element is ith index
            if (arr[i] == li.front())
            {
                li.pop_front();
            }
            i++;
            j++;
        }
    }
    return ans;
}