/*
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/



*/

// Logic -> similar to making BST from sorted array but here in list there is no indexing so we can find mid directly, therefore use slow and fast pointer to find mid
// create new node for mid
// left will be start to mid  pointer and right will be mid -> next to tail

// TC = O(n* log(n)), sc = (Log n) in avg case

TreeNode *solve(ListNode *head, ListNode *tail)
{
    if (head == tail)
    { // means when tail = mid, it is not included in left part
        return NULL;
    }

    ListNode *slow = head, *fast = head;
    while (fast != tail)
    { // Now tail will act as end means NULL
        fast = fast->next;
        if (fast != tail)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // now slow is pointing to mid node

    TreeNode *root = new TreeNode(slow->val);

    // left call
    root->left = solve(head, slow);

    // right call
    root->right = solve(slow->next, tail);

    return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
    TreeNode *root = solve(head, NULL);
    return root;
}