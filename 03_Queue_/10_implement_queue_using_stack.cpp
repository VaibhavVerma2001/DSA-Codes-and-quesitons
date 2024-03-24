// Problem - 
// https://leetcode.com/problems/implement-queue-using-stacks/description/

// solution - https://leetcode.com/problems/implement-queue-using-stacks/solutions/4907129/4-simple-and-easy-methods-with-comments-beats-100/


// Method 1 - Using single stack
// For peek() and pop() -> write delete at bottom function -> TC = O(N)
// class MyQueue {
// public:
//     stack<int> st;
//     void deleteBottom(stack<int> &st,int i, int n,int &ans){
//         if(st.empty() || (i == n)){
//             ans = st.top();
//             st.pop();
//             return;
//         }

//         int temp = st.top();
//         st.pop();

//         deleteBottom(st, i+1,n,ans);

//         st.push(temp);
//     }

//     void bottom(stack<int> &st,int i, int n, int & ans){
//         if(st.empty() || (i == n)){
//             ans = st.top();
//             return;
//         }

//         int temp = st.top();
//         st.pop();

//         bottom(st, i+1,n,ans);

//         st.push(temp);
//     }


//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         st.push(x);
//     }
    
//     int pop() {
//         int n = st.size(), i =1,ans;
//         deleteBottom(st,i,n,ans);
//         return ans;

//     }
    
//     int peek() {
//         int ans , n = st.size(), i =1;;
//         bottom(st,i,n,ans);
//         return ans;
//     }
    
//     bool empty() {
//         return st.empty();
//     }
// };


// Method 2 - Using single stack
// Insert At bottom for push() - TC O(N)
// For peek() and pop() -> st.top() element
class MyQueue {
public:
    stack<int> st;
    void insertAtBottom(stack<int> &st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, x);

        st.push(temp);
    }


    MyQueue() {
        
    }
    
    void push(int x) {
        insertAtBottom(st,x);
    }
    
    int pop() {
        int ele = st.top();
        st.pop();
        return ele;

    }
    
    int peek() {
        int ele = st.top();
        return ele;
    }
    
    bool empty() {
        return st.empty();
    }
};


// Method 3 - Using 2 stacks
// For push(x) - TC = O(N)
//                 i) push st1 to st2
//                ii) add to st1
//               iii) push st2 to st1
// For peek() and pop() -> st.top() element - TC = O(1)
// class MyQueue {
// public:
//     stack<int> st1, st2;

//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         // 1 - push all elements st1 to st2
//         while(!st1.empty()){
//             int temp = st1.top();
//             st2.push(temp);
//             st1.pop();
//         }

//         // 2 - push x in st1
//         st1.push(x);

//         // 3 - push st2 to st1
//         while(!st2.empty()){
//             int temp = st2.top();
//             st1.push(temp);
//             st2.pop();
//         }
//     }
    
//     int pop() {
//         int ele = st1.top();
//         st1.pop();
//         return ele;

//     }
    
//     int peek() {
//         int ele = st1.top();
//         return ele;
//     }
    
//     bool empty() {
//         return st1.empty();
//     }
// };


// Method 4 - Using 2 stacks
// For push(x) - st.top() -> TC = O(N)
// For peek() and pop() -> 
// if st2 is empty() -> push from st1 to st2 -> then st2.top()
// else st2.top()
// class MyQueue {
// public:
//     stack<int> st1, st2;

//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         st1.push(x);
//     }
    
//     int pop() {
//         if(!st2.empty()){
//             int ele = st2.top();
//             st2.pop();
//             return ele;
//         }
//         else{
//             // push all elements from st1 to st2
//             while(!st1.empty()){
//                 int temp = st1.top();
//                 st2.push(temp);
//                 st1.pop();
//             }

//             int ele = st2.top();
//             st2.pop();
//             return ele;
//         }

//     }
    
//     int peek() {
//         if(!st2.empty()){
//             int ele = st2.top();
//             return ele;
//         }
//         else{
//             // push all elements from st1 to st2
//             while(!st1.empty()){
//                 int temp = st1.top();
//                 st2.push(temp);
//                 st1.pop();
//             }

//             int ele = st2.top();
//             return ele;
//         }
//     }
    
//     bool empty() {
//         return st1.empty() && st2.empty();
//     }
// };
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */