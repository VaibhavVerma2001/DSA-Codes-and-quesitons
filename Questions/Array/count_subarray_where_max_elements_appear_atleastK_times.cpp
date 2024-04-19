// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/solutions/4944127/2-simple-and-easy-solution-with-comments/


class Solution {
public:
    // long long countSubarrays(vector<int>& arr, int k) {
    //     int i = 0, j = 0, n = arr.size();
    //     long long ans = 0;
    //     int maxi = *max_element(begin(arr), end(arr));

    //     unordered_map<int,int> m;

    //     while(j < n){
    //         m[arr[j]]++;

    //         // when freq of max element < k
    //         if(m[maxi] < k){
    //             j++;
    //         }

    //         else{
    //             while(m[maxi] >= k){
    //                 ans = ans + n - j;
    //                 m[arr[i]]--;
    //                 i++;
    //             }
    //             j++;
    //         }
    //     }
    //     return ans;
    // }


    // instead of map using count variable to count
    long long countSubarrays(vector<int>& arr, int k) {
        int i = 0, j = 0, n = arr.size();
        long long ans = 0;
        int maxi = *max_element(begin(arr), end(arr));

        int count = 0; // to count max element

        while(j < n){
            
            if(arr[j] == maxi){
                count++;
            }

            // when freq of max element < k
            if(count < k){
                j++;
            }

            else{
                while(count >= k){
                    ans = ans + n - j;
                    if(arr[i] == maxi){
                        count--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};