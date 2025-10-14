/*
https://leetcode.com/problems/longest-happy-string/description/

A string s is called happy if it satisfies the following conditions:
- s only contains the letters 'a', 'b', and 'c'.
- s does not contain any of "aaa", "bbb", or "ccc" as a substring.
- s contains at most a occurrences of the letter 'a'.
- s contains at most b occurrences of the letter 'b'.
- s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0
*/

class Solution {
public:

    // Solve first - https://leetcode.com/problems/reorganize-string/  (similar)

    // Algo  - Insert element with most frequency
    // STEP 1 - store freq of char
    // STEP 2 - max-heap ({freq,char})
    // STEP 3 - take 2 chars at time so that no 2 chars come adjacent . while(pq.size()>=2)
    // STEP 4 - at last there could be only 1 element in pq. pop that and push
    // TC = O(a + b + c), SC = O(1), since heap has 3 elements at max ->(ans string space not counted)

    struct Compare{
        bool operator()(pair<int,char>a , pair<int,char>b ){
            return a.first < b.first; // max heap
        }
    };

    string longestDiverseString(int a, int b, int c) {
        string ans;
        priority_queue<pair<int, char>, vector<pair<int,char>>, Compare> pq;
        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'}); // O(log 3)

        // O(a + b + c)
        while(pq.size() >=2){
            pair<int,char> p1 = pq.top();
            pq.pop();
            pair<int,char> p2 = pq.top();
            pq.pop();

            if(p1.first >=2){
                ans.push_back(p1.second);
                ans.push_back(p1.second);
                p1.first-=2;
            } else {
                ans.push_back(p1.second);
                p1.first--;
            }
            
            if(p2.first >=2 && p2.first > p1.first){ // extra condn so that push 2 elements of seond if it has more freq than 1st now, eg = a = 0, b = 8, c = 11. op = "ccbbccbbccbbccbbcc" ❌, correct = "ccbccbbccbbccbbccbc"
                ans.push_back(p2.second);
                ans.push_back(p2.second);
                p2.first-=2;
            } else {
                ans.push_back(p2.second);
                p2.first--;
            }

            // push to queue if possible
            if(p1.first > 0){
                pq.push(p1);
            }
            if(p2.first > 0){
                pq.push(p2);
            }
            
        }

        // there could be 1 element in pq
        if(!pq.empty()){
            pair<int,char> p = pq.top();
            if(p.first >=2){
                ans.push_back(p.second);
                ans.push_back(p.second);
                p.first-=2;
            } else {
                ans.push_back(p.second);
                p.first--;
            }
        }

        return ans;
    }
};