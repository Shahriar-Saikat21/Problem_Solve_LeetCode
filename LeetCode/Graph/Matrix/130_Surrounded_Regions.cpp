#include<bits/stdc++.h>

using namespace std;

/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' 
cells and none of the region cells are on the edge of the board.
A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

Example 1:

Input: board = [["X","X","X","X"],
                ["X","O","O","X"],
                ["X","X","O","X"],
                ["X","O","X","X"]]

Output: [["X","X","X","X"],
         ["X","X","X","X"],
         ["X","X","X","X"],
         ["X","O","X","X"]]

Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be 
surrounded.

Example 2:

Input: board = [["X"]]
Output: [["X"]]

*/

class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int row, int col) {
        // Check boundaries and stop if the current cell is not 'O'
        if (i < 0 || j < 0 || i >= row || j >= col || board[i][j] != 'O') return;

        // Mark the cell as visited by changing it to a placeholder (e.g., 'T')
        board[i][j] = 'T';

        // Explore adjacent cells
        dfs(board, i + 1, j, row, col); // Down
        dfs(board, i - 1, j, row, col); // Up
        dfs(board, i, j + 1, row, col); // Right
        dfs(board, i, j - 1, row, col); // Left
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();

        // Step 1: Mark all 'O' regions connected to the boundary
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0, row, col); // Left column
            if (board[i][col - 1] == 'O') dfs(board, i, col - 1, row, col); // Right column
        }
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j, row, col); // Top row
            if (board[row - 1][j] == 'O') dfs(board, row - 1, j, row, col); // Bottom row
        }

        // Step 2: Capture all remaining 'O' cells (not connected to the boundary)
        // and revert 'T' cells back to 'O'
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Captured
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O'; // Revert to original
                }
            }
        }
    }
};
