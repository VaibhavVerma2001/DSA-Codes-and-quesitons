class Solution {
public:
    int findPairs(vector<int>& arr, int k) {

        // Method 1 - Sorting , TC = O(N* log(N)), SC = O(1)
        sort(arr.begin(),arr.end());

        int i = 0 , j = 1, n = arr.size(), ans = 0;

        while(j<n){
            

            int diff = arr[j] - arr[i];

            if(diff == k){
                ans++;

                // ignore same pairs
                int c1 = arr[i], c2 = arr[j];
                while(i<n && c1 == arr[i]){
                    i++;
                }
                while(j < n && c2 == arr[j]){
                    j++;
                }
            }

            else if (diff > k){
                i++;
            }
            else{
                j++;
            }

            
            // for test case like nums = [1,3,1,5,4], k = 0 , when j and i both points to arr[i] == arr[j] == 3 
            if(i==j){
                j++;
            }
        }

        return ans;


        // Using unordered_map , TC = O(N), SC = O(N)
        // unordered_map<int,int> m;

        // for(auto &x : arr ){
        //     m[x]++;
        // }

        // int ans = 0;

        // for(auto x : m){
        //     int ele = x.first, freq = x.second;
        //     if(m.find(ele + k) != m.end()){
        //         if(ele != (ele + k)){
        //             ans++;
        //         }
        //         else if(m[ele] > 1){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
    }
};