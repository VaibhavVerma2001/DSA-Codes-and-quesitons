class Solution {
public:
    bool isPossible(vector<int> &nums, int mid,int k){
        int cnt = 1; //to count number of students
        int currSum = 0;

        for(auto &x : nums){
            // if any number is greater than mid then that is not possible solution
            if(x > mid){
                return false;
            }
            if(currSum + x <= mid){
                currSum +=x;
            }

            // give that book to other student
            else{
                cnt++;
                // reset sum for that student
                currSum = x;

                if(cnt > k){
                    return false;
                }
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // Same Book allocation problem

        // when k = 1, then we give all books to it only
        int e = accumulate(nums.begin(),nums.end(), 0), mid;
        int n = nums.size() , ans = -1;
        int s = 0;

        if(k > n){
            return -1;
        }

        while(s <= e){
            mid = s + (e-s)/2;

            if(isPossible(nums,mid,k)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};