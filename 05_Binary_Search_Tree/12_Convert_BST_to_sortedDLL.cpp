/*

https://www.naukri.com/code360/problems/bst-to-sorted-dll_1263694?leftPanelTabValue=PROBLEM

You are provided with a Binary Search Tree (BST), all you have to do is to convert it into the sorted doubly linked list (DLL).

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
0 <= N <= 10^4
-10^5 <= DATA <= 10^5

Time Limit: 1sec
Sample Input 1:
2
50 30 70 20 40 60 80 -1 -1 -1 -1 -1 -1 -1 -1
-1
Sample Output 1:
20 30 40 50 60 70 80 -1
-1
Explanation Of Sample Input 1:
For the first test case, the explanation is given in the description. -1 represents the end of DLL.

In the second test case, there is no node in BST and so, there is also no node in DLL.
Sample Input 2:
2
0 -2 -1 -3 -1 -1 -1
1 -1 2 -1 3 -1 -1
Sample Output 2:
-3 -2 0 -1
1 2 3 -1
Explanation Of Sample Input 2:
In the first test case, the sorted DLL formed is [-3, -2, 0].

In the second test case, the sorted DLL formed is [1, 2, 3].

*/

// Method 1 - Brute Force 
// store sorted array in array
// Then create DLL with that sorted array


void insertToDLL(TreeNode<int>* &head, TreeNode<int>* &tail, int data){
    TreeNode<int>* newNode = new TreeNode<int>(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail -> right = newNode;
        newNode -> left = tail;
        tail = newNode;
    }
}


void inorder(TreeNode<int> *root, TreeNode<int>* &head, TreeNode<int> *&tail){
    if(root == NULL){
        return ;
    }

    inorder(root -> left, head, tail);
    
    // insert in inorder 
    insertToDLL(head, tail,root -> data);

    inorder(root -> right, head, tail);
}

TreeNode<int>* bstToSortedDLL(TreeNode<int> *root){
	TreeNode<int>* head = NULL, *tail = NULL;
    inorder(root, head,tail);
    return head;
}







// Method 2 -> In place
// Do inorder and keep track of head and tail

void convertBSTtoDLL(TreeNode<int> *root, TreeNode<int> *&head, TreeNode<int> *&prev){
    if(root == NULL){
        return;
    }

    // left
    convertBSTtoDLL(root -> left, head,prev);

    // Node
    // Update head for 1st node only
    if(head == NULL){
        head = root;
    }
    else{
        prev -> right = root;
        root -> left = prev;
    }

    // update prev
    prev = root;
    

    // right
    convertBSTtoDLL(root -> right, head, prev);
}

TreeNode<int>* bstToSortedDLL(TreeNode<int> *root){
    TreeNode<int> *head = NULL, *prev = NULL;
    convertBSTtoDLL(root, head, prev);
    return head;
}