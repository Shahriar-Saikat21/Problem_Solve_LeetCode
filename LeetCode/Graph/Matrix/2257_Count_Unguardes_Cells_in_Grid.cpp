#include<bits/stdc++.h>

using namespace std;


/*
You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays 
guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith 
guard and jth wall respectively.
A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their 
position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that 
can see it.Return the number of unoccupied cells that are not guarded.

Example 1:

Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
Output: 7
Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
There are a total of 7 unguarded cells, so we return 7.

Example 2:

Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
Output: 4
Explanation: The unguarded cells are shown in green in the above diagram.
There are a total of 4 unguarded cells, so we return 4.

*/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int m, int n){       
        // Down direction
        for (int i = row + 1; i < m; i++) {
            if (grid[i][col] == 1 || grid[i][col] == 2) 
                break;  // Stop at wall or guard

            grid[i][col] = 3; //Mark safe by 'S'
        }

        // Right direction
        for (int j = col + 1; j < n; j++) {
            if (grid[row][j] == 1 || grid[row][j] == 2) 
                break; 

            grid[row][j] = 3;
        }

        // Up direction
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 1 || grid[i][col] == 2) 
                break;

            grid[i][col] = 3;
        }

        // Left direction
        for (int j = col - 1; j >= 0; j--) {
            if (grid[row][j] == 1 || grid[row][j] == 2)
                break; 

            grid[row][j] = 3;
        }       
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n,0));

        // 1=guard, 2=wall, 3=visited

        for(auto i:guards){
            grid[i[0]][i[1]] = 1;
        }

        for(auto i:walls){
            grid[i[0]][i[1]] = 2;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j,m,n);
                }
            }
        }

        // Count unguarded cells
        int countUnguardedCells = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    countUnguardedCells++;
                }
            }
        }

        return countUnguardedCells;
    }
};

//Another Solution
class Solution {
    /*
        0: Unguarded cell
        1: Guarded
        2: Guard Present
        3: Wall
    */
    vector<int> dir={-1,0,1,0,-1};
    void dfs(int x,int y,int direction,vector<vector<int>>& grid){
        if(x<0 or x>=grid.size() or y<0 or y>=grid[0].size() or grid[x][y]==2 or grid[x][y]==3)
            return;
        
        grid[x][y]=1;//Marked
        if(direction==0)        dfs(x-1,y,direction,grid);//Up
        else if(direction==1)   dfs(x,y+1,direction,grid);//Right
        else if(direction==2)   dfs(x+1,y,direction,grid);//Down
        else if(direction==3)   dfs(x,y-1,direction,grid);//Left
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        
        for(auto& guard: guards)
            grid[guard[0]][guard[1]]=2;

        for(auto& wall: walls)
            grid[wall[0]][wall[1]]=3;

        for(auto& guard: guards){
            for(int i=0;i<4;++i){
                int x = guard[0] + dir[i];
                int y = guard[1] + dir[i+1];
                dfs(x,y,i,grid);
            }
        }
        int unguarded = 0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j)
                if(grid[i][j]==0)
                    unguarded+=1;
        
        return unguarded;
    }
};