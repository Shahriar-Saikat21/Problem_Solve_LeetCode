#include<bits/stdc++.h>

using namespace std;

/*
You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.
Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) 
to the lower right corner (m - 1, n - 1).

Example 1:

Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
Output: 2
Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.

Example 2:

Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
Output: 0
Explanation: We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.

*/

class Solution {
    //Dijkstra Algorithm
    #define pip pair<int,pair<int,int>>
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        priority_queue<pip,vector<pip>,greater<pip>> minheap;
        minheap.push({0,{0,0}});
        visited[0][0]=true;

        while(!minheap.empty()){
            pip curr = minheap.top();
            minheap.pop();

            int x=curr.second.first;
            int y=curr.second.second;
            int cost=curr.first;
            
            if(x==m-1 and y==n-1)   return cost;

            for(int i=0;i<4;++i){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 and newX<m and newY>=0 and newY<n and !visited[newX][newY]){
                    visited[newX][newY] = true;
                    if(grid[newX][newY]==1){
                        minheap.push({cost+1,{newX,newY}});
                    }else{
                        minheap.push({cost,{newX,newY}});
                    }                        
                }
            }
        }
        return 0;
    }
};
