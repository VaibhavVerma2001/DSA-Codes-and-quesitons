// Print all permutation of string

// https://leetcode.com/problems/permutations/
// https://leetcode.com/problems/permutations-ii/description/
#include<bits/stdc++.h>
using namespace std;

// TC = Time Complexity: O(N * N!) Note that there are N! permutations and it requires O(N) time to print a permutation.
// Auxiliary Space: O(R – L)

void permutation(string &str, int i,vector<string> &ans){
    // BASE CASE
    if(i>= str.size()){
        ans.push_back(str);
        return ;
    }

    // Loop j = i to n-1 index and swap and try all positions
    for(int j = i ; j < str.length(); j++){
        // swap
        swap(str[i],str[j]);

        // Rec 
        permutation(str,i+1,ans);

        // Backtracking
        swap(str[i],str[j]);
    }
}

int main(){
    vector<string> ans;
    string str = "abc";
    int i = 0;
    permutation(str,i,ans);

    for(auto &x : ans){
        cout<<x<<endl;
    }
    return 0;
}

// Note this method will give duplicate permutations also when all characters or elements are not unique, so use set to store value then push them to vector

// OR make a map of swapped str[j] with str[i], if str[j] is already swapped then dont swap again
// https://leetcode.com/problems/permutations-ii/solutions/4656259/2-simple-and-easy-solutions-with-comments/