#include<bits/stdc++.h>

using namespace std;

/*
You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the 
minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) 
only when the time you visit it is greater than or equal to grid[row][col].
You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell 
in the four directions: up, down, left, and right. Each move you make takes 1 second.
Return the minimum time required in which you can visit the bottom-right cell of the matrix. 
If you cannot visit the bottom-right cell, then return -1.


Example 1:

Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
Output: 7
Explanation: One of the paths that we can take is the following:
- at t = 0, we are on the cell (0,0).
- at t = 1, we move to the cell (0,1). It is possible because grid[0][1] <= 1.
- at t = 2, we move to the cell (1,1). It is possible because grid[1][1] <= 2.
- at t = 3, we move to the cell (1,2). It is possible because grid[1][2] <= 3.
- at t = 4, we move to the cell (1,1). It is possible because grid[1][1] <= 4.
- at t = 5, we move to the cell (1,2). It is possible because grid[1][2] <= 5.
- at t = 6, we move to the cell (1,3). It is possible because grid[1][3] <= 6.
- at t = 7, we move to the cell (2,3). It is possible because grid[2][3] <= 7.
The final time is 7. It can be shown that it is the minimum time possible.

Example 2:

Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
Output: -1
Explanation: There is no path from the top left to the bottom-right cell.

*/

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Early exit if the starting conditions are invalid
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        // Visited array
        vector<vector<int>> visited(n, vector<int>(m, 0));
        // Priority queue to handle minimum time
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // Direction vectors
        int dir[] = {1, 0, -1, 0, 1};

        // Push the starting cell
        pq.push({0, 0, 0}); // {time, row, col}

        while (!pq.empty()) {
            int time = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
            pq.pop();

            // If reached bottom-right cell, return the time
            if (row == n - 1 && col == m - 1) return time;

            // Skip if already visited
            if (visited[row][col]) continue;

            visited[row][col] = 1;

            // Explore all four directions
            for (int i = 0; i < 4; i++) {
                int r = row + dir[i], c = col + dir[i + 1];

                // Check bounds and if already visited
                if (r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
                    int wait = (time >= grid[r][c]) ? 0 : (grid[r][c] - time + 1) % 2;
                    int newTime = max(grid[r][c], time + 1) + wait;
                    pq.push({newTime, r, c});
                }
            }
        }

        // If no path to bottom-right cell, return -1
        return -1;
    }
};


