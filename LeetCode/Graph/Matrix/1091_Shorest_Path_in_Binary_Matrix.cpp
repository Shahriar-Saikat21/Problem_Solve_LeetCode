#include<bits/stdc++.h>

using namespace std;


/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. 
If there is no clear path, return -1.
A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell 
(i.e., (n - 1, n - 1)) such that:

-All the visited cells of the path are 0.
-All the adjacent cells of the path are 8-directionally connected (i.e., 
they are different and they share an edge or a corner).
-The length of a clear path is the number of visited cells of this path.

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1 || grid[n-1][m-1]==1){
            return -1;
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        int delr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delc[8] = {-1,  0,  1, 1, 1, 0, -1, -1};
        int ans=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                if(row==n-1 && col==m-1){
                    return ans;
                }
                for(int i=0;i<8;i++){
                    int nrow=row+delr[i];
                    int ncol=col+delc[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]==1
                    && grid[nrow][ncol]==0){
                        q.push({nrow,ncol});
                        vis[nrow][ncol]=1;
                    }
                }  
            }
            ans++;
        }
        return -1;
    }
};


class SolutionDFS {
private : 
    typedef vector<vector<int>> vvi; 
    int xx[8] = {0,0,-1,1,-1,-1,1,1};
    int yy[8] = {1,-1,0,0,-1,1,1,-1}; 
    
    int shortestPathDFs(int x,int y, vvi &grid,vvi &visited,int n, int cells)
    {
         if(x == n-1 && y == n-1)
           return cells;
         int minCells = INT_MAX;
         visited[x][y] = 1;
         for(int i=0; i<8; i++)
         {
             int nx = x + xx[i], ny = y + yy[i];
             if(nx < n && nx >= 0 && ny < n && ny >=0 && !grid[nx][ny] && !visited[nx][ny]) 
                  minCells = min(minCells, shortestPathDFs(nx,ny,grid,visited,n,cells+1));
         }
         visited[x][y] = 0;
         return minCells;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0])
           return -1;
        if(n == 1) return 1;
        vector<vector<int>> visited(n,vector<int>(n,0)); 
        int ans = shortestPathDFs(0,0,grid,visited,n,1);
        return ans != INT_MAX ? ans : -1;
    }
};   