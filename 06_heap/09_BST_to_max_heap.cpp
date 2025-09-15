/*

Given a Binary Search Tree. Convert a given BST into a Special Max Heap with the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied on all the nodes in the so converted Max Heap.

Example 1:

Input :
                 4
               /   \
              2     6
            /  \   /  \
           1   3  5    7

Output : 1 2 3 4 5 6 7
Exaplanation :
               7
             /   \
            3     6
          /   \  /   \
         1    2 4     5
The given BST has been transformed into a
Max Heap and it's postorder traversal is
1 2 3 4 5 6 7.

*/

// Logic ->
// 1 - Get in sorted array -> inorder tarversal
// 2 - Overwrite Tree using LRN -> postorder

void inorder(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void convertToMaxHeap(Node *root, vector<int> &arr, int &index)
{
    if (root == nullptr)
    {
        return;
    }

    // Post order and fill -- LRN
    convertToMaxHeap(root->left, arr, index);
    convertToMaxHeap(root->right, arr, index);
    root->data = arr[index++];
}

void convertToMaxHeapUtil(Node *root)
{
    // Your code goes here
    vector<int> arr;
    int index = 0;
    inorder(root, arr);
    convertToMaxHeap(root, arr, index);
}

// Time Complexity: O(n)
// Auxiliary Space: O(n)

// Note for min heap -> Fill using Preorder