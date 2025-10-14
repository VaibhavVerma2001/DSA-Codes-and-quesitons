/*
https://www.geeksforgeeks.org/problems/minimum-sum4058/1

Given an array arr[ ] consisting of digits, your task is to form two numbers using all the digits such that their sum is minimized. Return the minimum possible sum as a string with no leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: "604"
Explanation: The minimum sum is formed by numbers 358 and 246.
Input: arr[] = [5, 3, 0, 7, 4]
Output: "82"
Explanation: The minimum sum is formed by numbers 35 and 047.
Input: arr[] = [9, 4]
Output: "13"
Explanation: The minimum sum is formed by numbers 9 and 4.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9



*/

class Solution {
  public:
    // Logic - sort array and give minimum number 1 by 1 in 2 parts
    // instead of sorting we can use min-heap too
    // TC = O(N)
    
    // helper function to add two strings
    string addStrings(string &s1, string &s2) {
        string ans = "";
        int carry = 0;

        int i = s1.length()-1, j = s2.length()-1;

        while(i>=0 && j>=0){
            int sum = (s1[i] - '0') + (s2[j] - '0') + carry;
            carry = sum/10;
            sum = sum%10;
            ans.push_back((sum + '0'));
            i--;
            j--;
        }

        while(i>=0){
            int sum = (s1[i] - '0') + carry;
            carry = sum/10;
            sum = sum%10;
            ans.push_back((sum + '0'));
            i--;
        }

        while(j>=0){
            int sum = (s2[j] - '0') + carry;
            carry = sum/10;
            sum = sum%10;
            ans.push_back((sum + '0'));
            j--;
        }

        while(carry){
            int sum = carry;
            carry = sum/10;
            sum = sum%10;
            ans.push_back((sum + '0'));
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
    
    string minSum(vector<int> &arr) {
        // code here
        string s1 , s2;
        sort(arr.begin(), arr.end());
        
        for(int i = 0 ; i < arr.size(); i+=2){
            s1.push_back(arr[i] + '0');
            if(i+1 < arr.size()){
                s2.push_back(arr[i + 1] + '0');
            }
        }
        
        // add two numbers as strings
        string ans = addStrings(s1, s2);

        // remove leading zeros
        int idx = 0;
        while (idx + 1 < ans.size() && ans[idx] == '0') idx++;
        return ans.substr(idx);
    }
};