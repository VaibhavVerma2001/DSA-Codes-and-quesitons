/*
https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

Given a Binary Search Tree that contains unique positive integer values greater than 0. The task is to complete the function isDeadEnd which returns true if the BST contains a dead end else returns false. Here Dead End means a leaf node, at which no other node can be inserted.

Example 1:

Input :   
               8
             /   \ 
           5      9
         /  \     
        2    7 
       /
      1     
          
Output : 
Yes
Explanation : 
Node 1 is a Dead End in the given BST.
Example 2:

Input :     
              8
            /   \ 
           7     10
         /      /   \
        2      9     13

Output : 
Yes
Explanation : 
Node 9 is a Dead End in the given BST.
Your Task: You don't have to input or print anything. Complete the function isDeadEnd() which takes BST as input and returns a boolean value.

Expected Time Complexity: O(N), where N is the number of nodes in the BST.
Expected Space Complexity: O(N)

Constraints:
1 <= N <= 1001
1 <= Value of Nodes <= 10001

*/

    // Method 1 - TC = SC = O(N)
    // Logic - use Rnage method , every node must lie between [low,high]
    // check if node node + 1 >= high && node - 1 <= low means now we cant insert more nodes 
    // bool solve(Node *root , int low , int high){
    //     if(root == nullptr){
    //         return false;
    //     }
        
    //     if(root -> left == nullptr && root -> right == nullptr){
    //         if(root -> data + 1 >= high && root -> data - 1 <= low){
    //             return true;
    //         }    
    //     }
        
        
    //     bool leftAns = solve(root -> left, low, root -> data);
    //     bool rightAns = solve(root -> right, root -> data, high);
        
    //     return leftAns || rightAns;
    // }
    
    // bool isDeadEnd(Node *root)
    // {
    //     //Your code here
    //     return solve(root,0,10001);
    // }
    
    
    // Method 2 - TC = SC = O(N)
    // Logic - For each node check if node + 1 and node - 1 already exists, then it can't be added again
    
    bool solve(Node *root, unordered_set<int> &s){
        if(root == nullptr){
            return false;
        }
        
        s.insert(root -> data);
        
        if(root -> left == nullptr && root -> right == nullptr){
            
            int high = root -> data + 1;
            int low = root -> data -1 == 0? root -> data : root -> data -1; // because when node == 1 then lower becomes 0 and we are not allowed to insert value <= 0
            if( s.find(high) != s.end() && s.find(low) != s.end() ){
                return true;
            }
        }
        
        bool leftAns = solve(root -> left, s);
        bool rightAns = solve(root -> right, s);
        
        return leftAns || rightAns;
    }
    
    
    bool isDeadEnd(Node *root)
    {
        //Your code here
        unordered_set<int>s;
        return solve(root,s);
    }