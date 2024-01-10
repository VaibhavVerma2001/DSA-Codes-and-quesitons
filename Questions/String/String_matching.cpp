// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

int strStr(string str, string pat)
{

    // Method 1 - Naive solution
    // TC = O(m*(n-m+1)), SC = O(1)
    // int n = str.length();
    // int m = pat.length();

    // for(int i = 0 ; i<=n-m ; i++)
    // {
    //     int j=0 ;
    //     for(j  ; j<m ; j++)
    //     {
    //         if (str[i+j] != pat[j])
    //         {
    //             break;
    //         }
    //     }
    //     if (j==m)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // Method 2 - Sliding window
    // TC = O(N), SC = (1) , because there are only 26 characters of english
    // WRONG ❌❌❌ Because when str = "mississippi" and pat = "pi" , this code will return ans = 7 , because "ip" is found there, and in map "ip" = "pi" (because of no ordereing)
    // unordered_map<char,int> s,p;

    // for(auto &c : pat){
    //     p[c]++;
    // }

    // int i = 0 , j = 0 , n = str.length();

    // while(j < n){
    //     s[str[j]]++;

    //     // if window size is less than pattern string size
    //     if((j-i+1) != pat.length()){
    //         j++;
    //     }

    //     else{
    //         // if values of both map are same
    //         if(s == p){
    //             return i;
    //         }

    //         // update map
    //         s[str[i]]--;
    //         if(s[str[i]] == 0){
    //             s.erase(str[i]);
    //         }
    //         // increment i,j
    //         i++;
    //         j++;
    //     }
    // }

    // return -1;

    // So to improve above code we can use different string in each window

    string temp;
    int i = 0, j = 0, n = str.length();

    while (j < n)
    {
        temp.push_back(str[j]);

        // if window size is less than pattern string size
        if ((j - i + 1) != pat.length())
        {
            j++;
        }

        else
        {
            // if both strings are same -> compare temp from ith index
            if (temp.substr(i) == pat)
            {
                return i;
            }

            // OR instead of doing substr we can erase 0th index each time and compare temp and pat
            // update string -> means erase 0th index value
            // temp.erase(temp.begin());
            // increment i,j
            i++;
            j++;
        }
    }

    return -1;
}