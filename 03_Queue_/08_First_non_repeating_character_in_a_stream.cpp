#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

// Time Complexity: O(26 * n)
// Auxiliary Space: O(n)
string FirstNonRepeating(string s)
{
    // Code here
    vector<int> freq(26, 0);
    queue<char> q;
    string ans;

    for (auto &x : s)
    {
        // keep track of freq and left to right chars
        freq[x - 'a']++;
        q.push(x);

        // check first non repeating
        while (!q.empty())
        {
            char ch = q.front();
            // if non repeating , add in answer
            if (freq[ch - 'a'] == 1)
            {
                ans.push_back(ch);
                break;
            }
            // remove repeating chars
            else
            {
                q.pop();
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string s = "aabc";
    cout<<FirstNonRepeating(s)<<endl; 

    s = "zz";
    cout<<FirstNonRepeating(s)<<endl; 

    s = "geeksforgeeksandgeeksquizfor";
    cout<<FirstNonRepeating(s)<<endl; 
    
    return 0;
}