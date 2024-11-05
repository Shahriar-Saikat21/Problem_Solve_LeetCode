#include<bits/stdc++.h>

using namespace std;

/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i, int j, int row, int col){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] != '1') return;

        // for marking a point as visited
        grid[i][j] = '2';

        dfs(grid,i+1,j,row,col); //top
        dfs(grid,i-1,j,row,col); //bottom
        dfs(grid,i,j+1,row,col); //right
        dfs(grid,i,j-1,row,col); // left 
        //dfs(grid,i-1,j-1,row,col); //top left diagonal
        //dfs(grid,i-1,j+1,row,col); //top right diagonal 
        //dfs(grid,i+1,j+1,row,col); //bottom right diagonal 
        //dfs(grid,i+1,j-1,row,col); //bottom left diagonal        
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        if(row==0) return 0;

        int numOfIsland = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j,row,col);
                    numOfIsland ++;
                }
            }
        }

        return numOfIsland;
    }
};
