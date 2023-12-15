// https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2023-12-13


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {

        // Logic -> make 2 vectors row and col 
        // it will store number of 1 in ith row and jth col
        // iterate matrix again and if mat[i][j] -> check if row[i] = 1 AND col[j] = 1 , ans++
        
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<int> row(m,0) , col(n,0);

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 1){
                    row[i]++, col[j]++;
                }
            }
        }

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 1){
                    if(row[i] == 1 && col[j] == 1){
                        ans++;
                    }
                }
            }
        }


        return ans;

    }
};