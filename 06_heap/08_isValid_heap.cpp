// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1


// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    // Complete BT - 
    // Calculate total number of nodes
    // Go to its child , find its index
    // If any child exists with index >= total number of nodes means there was 1 null node in between
    
    // Valid heap - 
    // Complete BT and,
    // check if leftSubtree is valid heap, right Subtree is valid heap and root is maximum of its childer
    int countNodes(Node* root){
        if(root == nullptr){
            return 0;
        }

        int leftAns = countNodes(root -> left);
        int rightAns = countNodes(root -> right);

        return leftAns + rightAns + 1;
    }

    bool isCompleteTree(Node *root,int n ,int index){
        if(root == nullptr){
            return true;
        }

        if(index >= n){
            return false;
        }

        bool leftAns = isCompleteTree(root -> left, n, index * 2 + 1);
        bool rightAns = isCompleteTree(root -> right, n, index * 2 + 2);

        return leftAns && rightAns;
        
    }
    
    
    pair<int, bool> isValidHeap(Node *root, pair<int, bool>&p){
        if(root == nullptr){
            return {0,true};
        }
        
        pair<int, bool> leftAns = isValidHeap(root -> left, p);
        pair<int, bool> rightAns = isValidHeap(root -> right, p);
        
        int first = max(max(leftAns.first, rightAns.first), root -> data); // find max of subtree
        bool second = leftAns.second && rightAns.second && root -> data == first; // check all 3 conditions
        return {first, second};
        
    }

    // Main function
    bool isHeap(Node* root) {
        // code here
        int n = countNodes(root);
        bool isComplete = isCompleteTree(root, n, 0);
        pair<int,bool> p; // <max of subtree, isSubtree valid>
        pair<int,bool> isHeap = isValidHeap(root, p);
        return isComplete && isHeap.second;
    }
};





// Another mwthod of CBT and valid heap -
/*

bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool foundNull = false;
    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();
        if(front  == nullptr){ 
            // mark true if null node found
            foundNull = true;
        } else {
            // if any non null node found after getting null node
            if(foundNull){
                return false;
            }
            q.push(front -> left);
            q.push(front -> right);
        }
    }
    return true;
}

bool isValidHeap(BinaryTreeNode<int>* root){
    if(root == nullptr){
        return true;
    }

    // check if parent > its child
    bool lchild = true, rchild = true;
    if(root -> left && root -> data < root -> left -> data){
        lchild = false;
    } 

    if(root -> right && root -> data < root -> right -> data){
        rchild = false;
    } 

    bool leftAns = isValidHeap(root -> left);
    bool rightAns = isValidHeap(root -> right);

    return (leftAns && rightAns && lchild && rchild);

}

bool isBinaryHeapTree(BinaryTreeNode<int>* root) {
    // Write your code here.
    return isCompleteTree(root) && isValidHeap(root);
    
}

*/



