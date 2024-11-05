#include<bits/stdc++.h>

using namespace std;


/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 
1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). 
Any cells outside of the grid are considered water cells.
An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells 
that make up this island in grid2.
Return the number of islands in grid2 that are considered sub-islands.

Example 1:

Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], 
grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

Example 2:

Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], 
grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

*/

class Solution {
public:
    bool island = false;
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m){
        if(grid1[i][j] != grid2[i][j]){
            island = false;
        }
        grid2[i][j] = 0;

        grid1[i][j] = 0;
        int a[] = {0, 0, 1, -1};
        int b[] = {1, -1, 0, 0};
        // traverse in all directions
        for(int k=0; k<4; k++){
            int x = i+a[k];
            int y = j+b[k];
            if(x >=0 && x< n && y>=0 && y<m && grid2[x][y] == 1 ){
                dfs(x, y, grid1, grid2, n, m);
                
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int n = grid2.size();
        int m = grid2[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j] == 1){
                    // assuming it is a subisland
                    island = true;
                    dfs(i, j, grid1, grid2, n, m);
                    // if dfs does not mark island false then increment count
                    if(island) count++;
                    
                }
            }
        }
        return count;
    }
};