// https://leetcode.com/problems/count-and-say/description/


class Solution {
public:

    // Method 1 - using recursion
    string countAndSay(int n) {
        // BC 
        if(n == 1){
            return "1";
        }

        // RC 
        string recAns = countAndSay(n-1);

        // Processing -> count occurances
        string result = "";
        int i = 0, len = recAns.length();
        while(i<len){
            int cnt = 0;
            char ch = recAns[i];

            while(i < len && ch == recAns[i]){
                i++;
                cnt++;
            }

           result.push_back((cnt + '0'));
           result.push_back(ch);
        }
        return result;
    }



    // Mehtod 2 - using loop
    // string countAndSay(int n) {
    //     if(n==1){
    //         return "1";
    //     }

    //     string ans = "1";

    //     // loop starts from 2 bec for n = 1 it is already talen in ans
    //     for(int i = 2 ; i <=n ; i++){

    //         string curr = ans;
    //         // empty ans for new string
    //         ans = "";

    //         int j = 0, len = curr.length();
    //         while(j < len){
    //             int cnt = 0;
    //             char ch = curr[j];
    //             while(j<len && curr[j] == ch){
    //                 j++;
    //                 cnt++;
    //             }
    //             ans.push_back((cnt + '0'));
    //             ans.push_back(ch);
    //         }
    //     }
    //     return ans;
    // }
};