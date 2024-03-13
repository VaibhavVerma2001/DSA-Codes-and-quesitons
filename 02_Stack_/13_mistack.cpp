// https://leetcode.com/problems/min-stack/description/


// Method 1 - Using Linked list 
// insert at head
// all methods TC = O(1)

class node{

    public: 
    int data;
    int mini;
    node *next;

    node(int data,int mini){
        this->data = data;
        this->mini = mini;
        this->next = NULL;
    }
};

class MinStack {
public:
    node *head = NULL;
    MinStack() {
        // do nothing
    }
    
    void push(int val) {
        // insert at head

        // if head is NULL
        if(head == NULL){
            node *newNode = new node(val,val);
            head = newNode;
        }
        else{
            int mini = min(val,head->mini);
            node *newNode = new node(val,mini);
            newNode->next = head;
            head = newNode;
        }
    }
    
    void pop() {
        head = head -> next;
    }
    
    int top() {
        return head -> data;
    }
    
    int getMin() {
        return head -> mini;
    }
};




// Method 2 - Using vector of pair (current ele, minimum till that)
// all methods TC = O(1)


class MinStack {
public:
    vector<pair<int,int>> v;
    MinStack() {
        // do nothing
    }
    
    void push(int val) {
        // 1st element
        if(v.size() == 0){
            pair<int,int> p;
            p.first = val;
            p.second = val; 
            v.push_back(p);
        }
        
        else{
            // check min element of last pair
            pair<int,int> prev = v.back();

            int mini = min(val, prev.second);
            pair<int,int> p;
            p.first = val;
            p.second = mini;
            v.push_back(p);
        }
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        pair<int,int> p = v.back();
        return p.first;
    }
    
    int getMin() {
        pair<int,int> p = v.back();
        return p.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */