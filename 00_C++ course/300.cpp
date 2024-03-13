#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int size = nums.size();
        int j = 0;
        for (int i = 0; i < (size-1) ; i++)
        {
            if (nums[i] != nums[i+1])
            {
                nums[j] = nums[i];
                j++;
            }
            else if (i==(size-1) && nums[j-1]!=nums[i])
            {
                nums[j] = nums[i];
                j++;
            }
            
        }
        return j;
    }
};

int main ()
{
    vector <int> v=  {0,0,1,1,1,2,2,3,3,4};

    Solution s1;
    int k = s1.removeDuplicates(v);

    for (int i = 0; i < k; i++)
    {
        cout<<v[i]<<" ";
    }
    
    return 0 ;
}