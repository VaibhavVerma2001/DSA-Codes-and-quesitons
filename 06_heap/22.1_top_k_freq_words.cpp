/*
https://leetcode.com/problems/top-k-frequent-words/description/

Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]

*/

class Solution {
public:
    // vector<string> topKFrequent(vector<string>& words, int k) {
    //     unordered_map<string,int> m;
    //     vector<string> ans;
    //     for(auto x : words){
    //         m[x]++;
    //     }

    //     // run loop k times and find max freq and then element to corresponding freq 
    //     while(k--){
    //         int freq = 0 ;
    //         string ele;
    //         for(auto x : m){
    //             if(x.second != -1){ // if -1 means it has been added already
    //                 if(x.second > freq){
    //                     freq = max(freq,x.second);
    //                     ele = x.first;
    //                 }
    //                 // Sort the words with the same frequency by their lexicographical order.
    //                 else if (x.second == freq){
    //                     ele = min(ele,x.first);
    //                 }
    //             }
    //         }

    //         ans.push_back(ele);
    //         // then erase that element from map , so that it dont come together
    //         m[ele] = -1; 
    //     }
    //     return ans;
    // }



    struct Compare {
        bool operator()(pair<int, string> a, pair<int, string> b) {
            if (a.first == b.first)
                return a.second < b.second; // lexicographically smaller has higher priority
            return a.first > b.first;       // higher freq has higher priority (min-heap)
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for (auto &x : words)
            m[x]++;

        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for (auto &x : m) {
            pq.push({x.second, x.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end()); // because since it is min heap so on top there are elements with least freq, so reverse
        return ans;
    }
    // TC = O(N LOG K), SC = O(N)
};




























