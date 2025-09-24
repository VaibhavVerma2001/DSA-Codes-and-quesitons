 // SIMILAR - https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
    // The idea is to use a min heap to efficiently track the smallest element among all lists at any given time by initially storing the first node from each list in the heap, then repeatedly extracting the minimum element to build the merged list while adding the next node from that same list to maintain the heap's role in finding the next smallest element.
    // Time Complexity: O(n * log k) , where n is the total sum of nodes from all lists.
    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* newNode = new ListNode(val);
        if(head == nullptr){
            head = newNode;
        } else {
            tail -> next = newNode;
        }
        tail = newNode;
    }

    struct Compare{
        bool operator()(ListNode* a, ListNode* b){
            return a -> val > b -> val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL, *tail = NULL;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Insert first node of all lists
        for(int i = 0 ; i < lists.size(); i++){
            if(lists[i]){
                pq.push(lists[i]);
            }
           
        }

        while(!pq.empty()){
            ListNode* top = pq.top();
            pq.pop();
            insertAtTail(head, tail, top -> val);
            if(top -> next){
                pq.push(top -> next);
            }
            delete top;
        }
        
        return head;
    }