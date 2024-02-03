#include<bits/stdc++.h>
using namespace std ;

bool isSafe(int newi, int newj, vector<vector<int>> &maze, int row, int col, vector<vector<bool>> &visited){
    // 1 - out of bound
    // 2 - open path
    // visited already or not

    if (
		(newi >= 0 && newi < row) &&
		(newj >= 0 && newj < col) &&
		maze[newi][newj] == 1 &&
		visited[newi][newj] == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void printAllPaths(vector<vector<int>> &maze, int row, int col, int srci, int srcj, string &output, vector<vector<bool>> &visited){

    // BC -> when src reached desination
    if(srci == row - 1 && srcj == col -1){
        cout<<output<<endl;
        return ;
    }

    // order of R,L,D,U does not matter

    // For UP
    int newi = srci - 1;
    int newj = srcj;
    if(isSafe(newi, newj, maze, row, col, visited)){
        // mark visited
        visited[newi][newj] = true;

        // RC
        output.push_back('U');
        printAllPaths(maze,row,col,newi,newj,output,visited);

        // BackTracking 
        output.pop_back(); // while coming back pop that direction
        visited[newi][newj] = false; // mark that non visited
    }


    // For DOWN
    newi = srci + 1;
    newj = srcj;
    if(isSafe(newi, newj, maze, row, col, visited)){
        // mark visited
        visited[newi][newj] = true;

        // RC
        output.push_back('D');
        printAllPaths(maze,row,col,newi,newj,output,visited);

        // BackTracking 
        output.pop_back(); // while coming back pop that direction
        visited[newi][newj] = false; // mark that non visited
    }

    // For RIGHT
    newi = srci;
    newj = srcj + 1;
    if(isSafe(newi, newj, maze, row, col, visited)){
        // mark visited
        visited[newi][newj] = true;

        // RC
        output.push_back('R');
        printAllPaths(maze,row,col,srci,newj,output,visited);

        // BackTracking 
        output.pop_back(); // while coming back pop that direction
        visited[newi][newj] = false; // mark that non visited
    }

    // For LEFT
    newi = srci;
    newj = srcj - 1;
    if(isSafe(newi, newj, maze, row, col, visited)){
        // mark visited
        visited[newi][newj] = true;

        // RC
        output.push_back('L');
        printAllPaths(maze,row,col,newi,newj,output,visited);

        // BackTracking 
        output.pop_back(); // while coming back pop that direction
        visited[newi][newj] = false; // mark that non visited
    }

}


int main ()
{
    
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    int row = maze.size(), col = maze[0].size();
    string output = ""; // like subseq. of string

    // to store visited points
    vector<vector<bool >> visited(row, vector<bool>(col, false));

    int srci = 0 , srcj = 0;

    if(maze[0][0] == 0){
        cout<<"No paths, becase rat is locked"<<endl;
    }
    else{
        visited[srci][srcj] = true;
        printAllPaths(maze, row, col, srci, srcj, output,visited);
    }

    return 0 ;
}