// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/


class Solution {
public:
    int minOperations(vector<int>& nums) {
//         Method 1 - 
        
//         unordered_map<int,int> m;
//         for(auto &x : nums){
//             m[x]++;
//         }
        
//         int op = 0;
        
//         for(auto x : m){
//             int freq = x.second;
//             // first do second operation of taking 3 elements, to minimize operations
//             //till freq >= 5, we can keep on reducing 3 elements 
//             while(freq > 4){

//                 freq-=3;
//                 op++;
//             }

            
//             if(freq == 4){
//                 op+=2; // take 2,2 
//             }
//             else if(freq ==2 || freq == 3){
//                 op++; // either 2 or 3 elements
//             }
//             else if (freq == 1){
//                 return -1;
//             }

//         }
//         return op;
        
        
        
        // Method 2 - 
        // if n % 3 == 0, like 3,6,9,12... 
        // then op = n/3
        
        // if n%3 == 1, like 4,7,10,13...
        // then make 2 pairs of 2 , and rest pairs of 3
        // ex 13 ->
        // 13 - 2 - 2 = 9 (2 opn)
        // 9/3 = 3 opn
        // total 5 opn
        
        // if n%3 == 2, like 2,5,8,11...
        // then make 1 pair of 2 and rest pairs of 3
        // ex 11 ->
        // 11 - 2 = 9 (1 opn)
        // 9/3 = 3 opn 
        // total 4 opn
        
        
        
        unordered_map<int,int> m;
        for(auto &x : nums){
            m[x]++;
        }
        
        int op = 0;
        
        for(auto x : m){
            int freq = x.second;
            
            if(freq == 1){
                return -1;
            }
            
            if (freq % 3 == 0){
                op = op + freq/3;
            }
            
            //ex 13 -> 13 - 2 - 2 => 9 (leave 2 pairs of 2,2)
            if(freq % 3 == 1){
                freq = freq - 2 - 2;
                op = op + freq/3 + 2;
            }
            
            //ex 14 -> 14 - 2  => 12 (leave 2 pairs of 2,2)
            if(freq % 3 == 2){
                freq = freq - 2;
                op = op + freq/3 + 1;
            }
        }
        return op;
    }
};