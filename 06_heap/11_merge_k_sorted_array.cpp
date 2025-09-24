class Solution {
  public:
    // Step-By-Step Approach:
    // Create a min-heap and insert the first element of each of the k sorted arrays along with its array and element index.
    // Run a loop while the min-heap is not empty.
    // Remove (pop) the smallest element from the min-heap and push it to the output array.
    // Insert the next element from the same array (from which the popped element came) into the heap, if it exists.
    // Repeat this process until all elements from all arrays have been processed and the heap becomes empty.
    // Finally, return the merged output array containing all elements in sorted order.
    // [value, row(array), col(index)] -> store like this
    
    // Time Complexity: O(k2*Log(k))
    // Auxiliary Space: O(k2)
    
    // struct Compare {
    //     bool operator()(vector<int> a , vector<int> b) {
    //         return a[0] > b[0]; // smaller element has higher priority // min heap
    //     }
    // };


    
    // vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    //     // code here
    //     vector<int> ans;
    //     priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        
    //     // insert first elements of each row
    //     for(int i = 0 ; i < arr.size(); i++){
    //         pq.push({arr[i][0], i, 0});
    //     }
        
    //     while(!pq.empty()){
    //         vector<int> top = pq.top();
    //         pq.pop();
            
    //         int value = top[0], row = top[1], col = top[2];
    //         ans.push_back(value);
    //         col++;
            
    //         // insert next elements of that array if exists
    //         if(col  < arr[row].size()){
    //             int element = arr[row][col];
    //             pq.push({element, row, col});
    //         }
            
    //     }
    //     return ans;
    // }
    
    
    
    // Same logic but storing in class instead of vector
    
    class Item{
        public:
        int value;
        int row;
        int col;
        
        Item(int value, int row, int col){
            this -> value = value;
            this -> row = row;
            this -> col = col;
        }
    };
    
    struct Compare {
        bool operator()(Item *a , Item *b) {
            return a -> value > b -> value; // smaller element has higher priority // min heap
        }
    };
    


    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        vector<int> ans;
        priority_queue<Item*, vector<Item*>, Compare> pq;
        
        // insert first elements of each row
        for(int i = 0 ; i < arr.size(); i++){
            Item* temp = new Item(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        while(!pq.empty()){ // m * n times this loop runs
            Item *top = pq.top();
            pq.pop();
            
            int value = top -> value, row = top -> row, col = top -> col;
            ans.push_back(value);
            col++;
            
            // insert next elements of that array if exists
            if(col  < arr[row].size()){
                int element = arr[row][col];
                Item *temp = new Item(element, row, col);
                pq.push(temp); // log(m) TC to insert in heap
            }
            
            delete top;
            
        }
        return ans;
    }
};