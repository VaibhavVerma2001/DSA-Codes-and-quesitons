/*
Explanation -> https://www.youtube.com/watch?v=qlgeXDM1z7A
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.
 

Example 1:

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.
Example 2:

Input: grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
Output: 28
Explanation:
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
Path to get the maximum gold, 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 15
0 <= grid[i][j] <= 100
There are at most 25 cells containing gold.

*/

class Solution {
public:
    // Logic ->
    // starting from each cell where grid[i][j] != 0, check max amount of gold we can collect

    // create a function to find all possible ways to collect gold
    // mark visited cell = 0, and BT to its original value

    // TC of this dfs = 4^(m*n)
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
        // BC
        if(i >= m || j >= n || i < 0 || j < 0 || grid[i][j] == 0){
            return 0;
        }

        // mark visited
        int current = grid[i][j];
        grid[i][j] = 0;


        // RC -> 4 options -> U,D,L,R
        int option1 = dfs(grid,i-1,j,m,n); // Up
        int option2 = dfs(grid,i+1,j,m,n); // Down
        int option3 = dfs(grid,i,j-1,m,n); // left
        int option4 = dfs(grid,i,j+1,m,n); // right

        int maxi = max(max(option1,option2),max(option3,option4));

        // BT
        grid[i][j] = current;

        return (current + maxi);
    }


    // Main funtion
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxGold = 0;

        // start from each cell != 0
        for(int i = 0 ; i < m; i++){
            for(int j = 0 ; j < n; j++){
                if(grid[i][j] != 0){
                    maxGold = max(maxGold, dfs(grid,i,j,m,n));
                }
            }
        }
        return maxGold;
    }

    // total TC = O( (m*n)*(4^(m*n)) )
    // SC = O(4^(m*n))
};