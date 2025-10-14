/*
https://leetcode.com/problems/reorganize-string/description/

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/

class Solution {
public:
    // logic -
    // consume char with max freq first
    // TC = SC = O(N)
    // string reorganizeString(string str) {
    //     int arr[26] = {0};
    //     for(char &ch : str){
    //         arr[ch -'a']++;
    //     }

    //     string temp;

    //     // insert 1 element with max freq
    //     int maxFreq = 0, maxIndex = 0;
    //     for(int i = 0 ; i < 26; i++){ // O(26)
    //         if(arr[i] > maxFreq){
    //             maxFreq = arr[i];
    //             maxIndex = i;
    //         }
    //     }
    //     temp.push_back(char('a' + maxIndex));
    //     arr[maxIndex]--;

    //     while(temp.length() != str.length()){ // O(N)
    //         bool found = false;
    //         int maxFreq = 0, maxIndex = 0;
    //         for(int i = 0 ; i < 26; i++){ // O(26)
    //             if(temp.back() != char('a' + i) && arr[i] > 0){
    //                 if(arr[i] > maxFreq){
    //                     found = true;
    //                     maxFreq = arr[i];
    //                     maxIndex = i;
    //                 }
    //             }
    //         }
    //         if(!found){
    //             cout << temp;
    //             return "";
    //         }
    //         temp.push_back(char('a' + maxIndex));
    //         arr[maxIndex]--;
    //     }
    //     return temp;
    // }



    // Method 2 - 
    // STEP 1 - store freq of char, if any char freq > ceil(n/2) or (n+1)/2 then no possible arrangement ""
    // STEP 2 - max-heap ({freq,char})
    // STEP 3 - take 2 chars at time so that no 2 chars come adjacent . while(pq.size()>=2)
    // STEP 4 - at last there could be only 1 element in pq. pop that and push
    // TC = SC = O(N)


    struct Compare{
        bool operator()(pair<int,char>a , pair<int,char>b ){
            return a.first < b.first; // max heap
        }
    };

    string reorganizeString(string str) {
        priority_queue< pair<int,char>, vector<pair<int,char>>, Compare > pq;
        int n = str.length();
        string ans ;

        // STEP 1
        int freq[26] = {0};
        for(auto &ch : str){ // O(N)
            freq[ch-'a']++;
            if(freq[ch-'a'] > (n+1)/2){
                return "";
            }
        }

        // STEP 2
        for(char ch = 'a'; ch <= 'z'; ch++){ // O(26)
            if(freq[ch - 'a']){
                pair<int,char> p = {freq[ch - 'a'], ch};
                pq.push(p);
            }

        }

        // STEP 3
        while(pq.size() > 1){ // O(N)
            pair<int,char> p1 = pq.top();
            pq.pop();
            pair<int,char> p2 = pq.top();
            pq.pop();

            ans.push_back(p1.second); 
            ans.push_back(p2.second);

            p1.first--;
            p2.first--;

            if(p1.first){
                pq.push(p1);
            }

            if(p2.first){
                pq.push(p2);
            }
        }

        // STEP 4
        if(!pq.empty()){
            ans.push_back(pq.top().second);
        }
        return ans;
    }

    
};