// https://leetcode.com/problems/validate-binary-search-tree/

/*

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

*/

// Method 1 --> inorder traversal of BST is sorted
// so do traversal and keep track of inorder and check if next element coming is >= previous element
void inorder(TreeNode *root, bool &ans, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, ans, arr);

    int data = root->val;
    if (arr.size() > 0 && arr.back() >= data)
    {
        ans = false;
    }
    arr.push_back(data);

    inorder(root->right, ans, arr);
}

bool isValidBST(TreeNode *root)
{
    bool ans = true;
    vector<int> arr;
    inorder(root, ans, arr);
    return ans;
}

// Method 2 -> R > N > L so use range such that root -> val can be between lower and upper bound
bool solve(TreeNode *root, long long lowerBound, long long upperBound)
{
    if (root == NULL)
    {
        return true;
    }

    bool cond1 = root->val > lowerBound;
    bool cond2 = root->val < upperBound;

    bool leftAns = solve(root->left, lowerBound, root->val); // now upperBound = root -> val bec lchild should have smaller value than that

    bool rightAns = solve(root->right, root->val, upperBound); // now lowerBound = root -> val bec rchild should have greater value than that

    return (cond1 && cond2 && leftAns && rightAns);
}

bool isValidBST(TreeNode *root)
{
    long long lowerBound = -2147483657, upperBound = 2147483657; // some random number less than and INT_MIN and more than INT_MAX bec root -> val be INT_MAX AND INT_MIN
    return solve(root, lowerBound, upperBound);
}