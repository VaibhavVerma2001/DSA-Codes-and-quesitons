// Given an array arr of integers of size n. We need to compute the sum of elements from index i to index j. The queries consisting of i and j index values will be executed multiple times. 

// Input 1 : arr[] = {1, 2, 3, 4, 5}
//         i = 1, j = 3
//         i = 2, j = 4
// Output :  9
//          12         
// Input 2 : arr[] = {1, 2, 3, 4, 5}
//         i = 0, j = 4 
//         i = 1, j = 2 
// Output : 15
//           5


#include<iostream>
#include<vector>
using namespace std ;

// Method 1 - simply loop through each query and then loop array and find sum from q[0] to q[1]
// TC = O(n*q) , SC = O(1)

vector<int> solve1(vector<int> arr, vector<vector<int>> queries){

    vector<int> ans;

    for(int i = 0 ; i < queries.size() ; i++){
        int s = queries[i][0], e = queries[i][1];

        // mow loop and calculate the sum
        int sum = 0;
        for(int i = s; i <= e; i++){
            sum+= arr[i];
        }

        ans.push_back(sum);
    }
    return ans;
}



// Method 2 - using prefix sum -> store prfex sum
// sum (s...e) = sum(0...e) - sum (0...s-1);
// eg - sum (2...4) = sum(0...4) - sum(0...1)
// TC = O(N + Q) , SC = O(N) => for psum array

vector<int> solve2(vector<int> arr, vector<vector<int>> queries, vector<int> psum){

    vector<int> ans;

    for(int i = 0 ; i < queries.size() ; i++){
        int s = queries[i][0], e = queries[i][1];
        int sum = 0;

        // if s = 0 , psum[-1] does not exist, so handle it 
        if(s!=0){
            sum = psum[e] - psum[s-1];
        }
        else{
            sum = psum[e];
        }


        ans.push_back(sum);
    }
    return ans;
}

int main ()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<vector<int>> queries = {{1,3} , {2,4},{0,4} , {1,2}};

    vector<int> ans;
    // ans = solve1(arr,queries);


    // make psum array 
    vector<int> psum;
    int sum = 0;
    for(auto x : arr){
        sum+=x;
        psum.push_back(sum);
    }
    
    ans = solve2(arr,queries,psum);

    cout<<"Ans is : "<<endl;
    for(auto &x : ans){
        cout<<x<<" ";
    }
    return 0 ;
}