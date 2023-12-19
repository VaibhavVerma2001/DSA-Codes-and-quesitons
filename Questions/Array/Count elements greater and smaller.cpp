// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/description/

// https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/solutions/4417513/3-simple-easy-methods-with-comments-beats-100/


class Solution {
public:
    int countElements(vector<int>& arr) {

        int n = arr.size(), cnt = 0;
        
        // Method 1 - O(n*n) -> brute force
        // for(int i = 0 ; i < n ; i++){
        //     bool big = false, small = false;
        //     for(int j = 0 ; j < n ; j++){
        //         if(arr[j] > arr[i]){
        //             big = true;
        //         }
        //         else if (arr[j] < arr[i]){
        //             small = true;
        //         }
        //     }
        //     if(big && small){
        //         cnt++;
        //     }
        // } 
        // return cnt;


        // Method 2 - sorting

        
        // sort(arr.begin(), arr.end());
        // int i = 0 , j = n-1; //they will point to min and max element
        // // total ans lies between them => j - i + 1;

        // while(i<n && arr[i] == arr[0]){
        //     i++;
        // }
        // while(j>=0 && arr[j] == arr[n-1]){
        //     j--;
        // }

        // // for same elements [0,0,0,0,0,0,0,0,0,0,0,0,0,0] , op = 0
        // if(arr[0] == arr[n-1]){
        //     return 0;
        // }

        // cnt = j - i + 1;

        // return cnt;


        // Method 3 - find min and max element, then count ele. > min && ele < max
        // O(N) TC
        int maxi = *max_element(arr.begin(),arr.end());
        int mini = *min_element(arr.begin(),arr.end());

        for(auto x : arr){
            if(x > mini && x < maxi){
                cnt++;
            }
        }
        return cnt;
    }
};