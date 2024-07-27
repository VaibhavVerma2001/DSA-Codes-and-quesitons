/*

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.



Example 1:


Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.
Example 2:


Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.


Constraints:

1 <= descriptions.length <= 104
descriptions[i].length == 3
1 <= parenti, childi <= 105
0 <= isLefti <= 1
The binary tree described by descriptions is valid.


Hint 1
Could you represent and store the descriptions more efficiently?
Hint 2
Could you find the root node?
Hint 3
The node that is not a child in any of the descriptions is the root node.

*/

TreeNode *solve(int rootVal, unordered_map<int, pair<int, int>> &m)
{
    if (rootVal == 0)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(rootVal);
    if (m.find(rootVal) == m.end())
    {
        root->left = solve(0, m);
        root->right = solve(0, m);
    }
    else
    {
        int leftVal = m[rootVal].first;
        int rightVal = m[rootVal].second;

        root->left = solve(leftVal, m);
        root->right = solve(rightVal, m);
    }
    return root;
}

TreeNode *createBinaryTree(vector<vector<int>> &arr)
{
    // create map to store root with its child
    // also to find root (which is not child of any node) -> create set
    unordered_map<int, pair<int, int>> m;
    unordered_set<int> s;
    for (auto &x : arr)
    {
        s.insert(x[1]);
        if (x[2] == 1)
        {
            m[x[0]].first = x[1];
        }
        else
        {
            m[x[0]].second = x[1];
        }
    }

    // calculate root -> which is not child of any node
    int rootVal = 0;
    for (auto &x : m)
    {
        if (s.find(x.first) == s.end())
        {
            rootVal = x.first;
            break;
        }
    }

    TreeNode *root = solve(rootVal, m);

    return root;
}

// Method 2 -> https://www.youtube.com/watch?v=Rt2prDOV2hU
// Simply traverse array, keep track of TreeNode* whose node is created
// if not created then create and add child to it's left or right
// map of type <int,TreeNode*>
TreeNode *createBinaryTree(vector<vector<int>> &arr)
{
    unordered_map<int, TreeNode *> m;
    unordered_set<int> s;

    for (auto &x : arr)
    {
        // create node if not found
        if (m.find(x[0]) == m.end())
        {
            m[x[0]] = new TreeNode(x[0]);
        }
        if (m.find(x[1]) == m.end())
        {
            m[x[1]] = new TreeNode(x[1]);
        }

        if (x[2] == 1)
        {
            m[x[0]]->left = m[x[1]];
        }
        else
        {
            m[x[0]]->right = m[x[1]];
        }

        s.insert(x[1]); // store child nodes
    }

    TreeNode *root = NULL;
    for (auto &x : arr)
    {
        if (s.find(x[0]) == s.end())
        {
            root = m[x[0]];
            break;
        }
    }

    return root;
}