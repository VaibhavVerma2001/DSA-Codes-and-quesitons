/*
https://www.geeksforgeeks.org/problems/median-of-bst/1

Given a Binary Search Tree of size N, find the Median of its Node values.

Example 1:

Input:
       6
     /   \
   3      8   
 /  \    /  \
1    4  7    9
Output: 6
Explanation: Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.


Example 2:

Input:
       6
     /   \
   3      8   
 /   \    /   
1    4   7   
Output: 5
Explanation:Inorder of Given BST will be:
1, 3, 4, 6, 7, 8. So, here median will
(4 + 6)/2 = 10/2 = 5.
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findMedian() which takes the root of the Binary Search Tree as input and returns the Median of Node values in the given BST.
Median of the BST is:

If number of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2
If number of nodes are odd : then median = (N+1)/2th node.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).


Constraints:
1<=N<=10000

*/



// TC = SC = O(N)
// Count total number of nodes
// Then find desired node
// for SC = O(1) , use morris traversal twice, for counting and reaching desired node

// to count number of nodes
int lvlOrder(struct Node *root){
    if(root == nullptr){
        return 0;
    }
    int count = 0;
    queue<struct Node*> q;
    q.push(root);
    
    
    while(!q.empty()){
        struct Node *front = q.front();
        q.pop();
        count++;
        
        if(front -> left){
            q.push(front -> left);
        }
        
        if(front -> right){
            q.push(front -> right);
        }
    }
    return count;
}


void inorder(struct Node *root, int &ans, int &i, int n){
    if(!root){
        return ;
    }
    
    inorder(root -> left,ans,i,n);
    
    i++;
    
    // For odd
    if(n % 2 == 1 && i == (n+1)/2){
        ans = root -> data;
        return;
    }
    
    // For even
    if(n % 2 == 0 && i == (n/2)){
        ans += root -> data;
    }
    
    if(n % 2 ==0 && i == ((n/2)+1)){
        ans += root -> data;
        return ;
    }
    
    
    inorder(root -> right,ans,i,n);
}


float findMedian(struct Node *root)
{
    //Code here
    int n = lvlOrder(root);
    int ans = 0, i = 0;
    inorder(root, ans, i, n);
    return n & 1 ? ans : float(ans)/2; 
}