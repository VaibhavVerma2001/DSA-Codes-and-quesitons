// https://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/
node* convertDLLtoBST(node* &head, int n) {
    if(head == NULL || n <= 0){
        return NULL;
    }

    // Left
    node *leftSubTree = convertDLLtoBST(head, n/2);

    // Node
    node *root = head;
    root -> left = leftSubTree;

    // update head
    head = head -> next;

    // Right
    node *rightSubTree = convertDLLtoBST(head, n - n/2 - 1);
    root -> right = rightSubTree;


    return root;
}