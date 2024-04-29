/*
https://leetcode.com/problems/smallest-string-starting-from-leaf/description/

You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

 

Example 1:


Input: root = [0,1,2,3,4,3,4]
Output: "dba"
Example 2:


Input: root = [25,1,3,1,3,0,2]
Output: "adz"
Example 3:


Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
 

Constraints:

The number of nodes in the tree is in the range [1, 8500].
0 <= Node.val <= 25

*/

// Method 1 - explore all path from root to leaf
// then reverse path and store in vector or add in front
// then sort vector and return 1st one

// void solve(TreeNode *node , vector<string> &path, string curr){
//     // BC
//     if(node == NULL){
//         return;
//     }

//     // curr.push_back(node -> val + 'a');
//     //OR add in front so no need to reverse
//     curr = (char)(node -> val + 'a') + curr;

//     if(node -> left == NULL && node -> right == NULL){
//         // reverse string bec we need from leaf to root
//         // reverse(curr.begin(),curr.end());
//         path.push_back(curr);
//     }

//     solve(node -> left,path,curr);
//     solve(node -> right,path,curr);

// }
// string smallestFromLeaf(TreeNode* root) {
//     vector<string> path;
//     solve(root,path, "");
//     // sort to arrange in lexicographically order
//     sort(path.begin(),path.end());
//     return path[0];
// }



// Method 2 - same as method 1 -> just take ans string instead of vector
// to store smallest string

void solve(TreeNode *node, string &ans, string curr)
{
    // BC
    if (node == NULL)
    {
        return;
    }

    curr.push_back(node->val + 'a');

    if (node->left == NULL && node->right == NULL)
    {
        // reverse string bec we need from leaf to root
        reverse(curr.begin(), curr.end());
        // for first time when ans is empty
        if (ans == "")
        {
            ans = curr;
        }
        ans = min(ans, curr);
    }

    solve(node->left, ans, curr);
    solve(node->right, ans, curr);
}
string smallestFromLeaf(TreeNode *root)
{
    string ans;
    solve(root, ans, "");
    return ans;
}



// Method 3 - same as method 12 -> Just With BT, taking curr as address
// void solve(TreeNode *node , string &ans, string &curr){
//     // BC
//     if(node == NULL){
//         return;
//     }

//     curr.push_back(node -> val + 'a');

//     if(node -> left == NULL && node -> right == NULL){
//         // reverse string bec we need from leaf to root
//         cout<<curr<<endl;
//         string temp = curr;
//         reverse(temp.begin(),temp.end());
//         // for first time when ans is empty
//         if(ans == ""){
//             ans = temp;
//         }
//         ans = min(ans,temp);
//     }

//     solve(node -> left,ans,curr);
//     solve(node -> right,ans,curr);

//     // BT
//     curr.pop_back();

// }
// string smallestFromLeaf(TreeNode* root) {
//     string ans,curr;
//     solve(root,ans,curr);
//     return ans;
// }