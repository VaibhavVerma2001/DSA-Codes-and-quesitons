/*

https://leetcode.com/problems/find-duplicate-subtrees/description/

Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.



Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]


Example 2:
Input: root = [2,1,1]
Output: [[1]]

Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]


Constraints:

The number of the nodes in the tree will be in the range [1, 5000]
-200 <= Node.val <= 200

*/

// Logic -> do preorder traversal and make encoding string including NULL so that we can make sure of structure and store them in map, if same encoding found then take that in answer
// taking map to count occurances such that if, m[encoding] > 2 , we dont take that root again, like in root = [1,2,3,4,null,2,4,null,null,4], op = [[2,4],[4]]
// TC = SC = O(N)
string solve(TreeNode *root, unordered_map<string, int> &m, vector<TreeNode *> &ans)
{
    if (root == NULL)
    {
        return "N";
    }

    string leftAns = solve(root->left, m, ans);
    string rightAns = solve(root->right, m, ans);

    string encode = to_string(root->val) + "," + leftAns + "," + rightAns;

    if (m.find(encode) != m.end() && m[encode] == 1)
    { // take for 1st time only
        ans.push_back(root);
    }

    m[encode]++;

    return encode;
}

vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
{
    vector<TreeNode *> ans;
    unordered_map<string, int> m;
    solve(root, m, ans);
    return ans;
}