/*

https://leetcode.com/problems/balance-a-binary-search-tree/description/

Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.


Example 2:
Input: root = [2,1,3]
Output: [2,1,3]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 105

*/


    // Convert the tree to a sorted array using an in-order traversal.
    // Construct a new balanced tree from the sorted array recursively.
    // TC = SC = O(N)

    void inorder(TreeNode* root, vector<int> &v){
        if(!root){
            return;
        }

        inorder(root -> left, v);
        v.push_back(root -> val);
        inorder(root -> right, v);
    }

    TreeNode* generateBSTfromSortedArray(vector<int> &v, int s, int e){
        if(s > e){
            return NULL;
        }

        int mid = s + (e-s)/2;

        TreeNode* root = new TreeNode(v[mid]);

        root -> left =  generateBSTfromSortedArray(v,s,mid-1);
        root -> right = generateBSTfromSortedArray(v,mid+1,e);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        // Make sorted array using inorder traversal
        vector<int> v;
        inorder(root,v);

        // Generate BST from sorted array
        return generateBSTfromSortedArray(v,0,v.size()-1);
    }