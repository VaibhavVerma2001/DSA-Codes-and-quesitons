/*
https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/


You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.



Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109

*/

// Logic - Create and hash map with key = sum of digits and value max heap, so that top elements remain at top
// traverse map and find sum of top 2 elements and update max

// calculate digit sum
int digitSum(int num)
{
    int sum = 0;
    while (num)
    {
        int rem = num % 10;
        sum += rem;
        num /= 10;
    }
    return sum;
}

int maximumSum(vector<int> &nums)
{
    int ans = -1;
    // create min heap, so that largest element remain at bottom
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
    for (auto &x : nums)
    {
        int digitsum = digitSum(x);
        if (m[digitsum].size() < 2)
        {
            m[digitsum].push(x);
        }
        else
        {
            // push only if x > top element, bec then it can be largest only
            if (m[digitsum].top() < x)
            {
                m[digitsum].pop();
                m[digitsum].push(x);
            }
        }
    }

    for (auto &x : m)
    {
        priority_queue<int, vector<int>, greater<int>> pq = x.second;
        if (pq.size() == 2)
        {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            ans = max(ans, (first + second));
        }
    }
    return ans;
}