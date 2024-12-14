#include<bits/stdc++.h>

using namespace std;
/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or 
vertically neighboring. The same letter cell may not be used more than once.

Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/

class Solution {
public:
    // Helper function for backtracking
    bool backtrack(vector<vector<char>>& board, string& word, int r, int c, int index) {
        // If we've matched the whole word, return true
        if (index == word.size()) 
            return true;

        // Boundary checks and character mismatch
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) 
            return false;

        // Mark the cell as visited by temporarily modifying it
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 possible directions
        bool found = 
            backtrack(board, word, r + 1, c, index + 1) || 
            backtrack(board, word, r - 1, c, index + 1) || 
            backtrack(board, word, r, c + 1, index + 1) || 
            backtrack(board, word, r, c - 1, index + 1);

        // Restore the cell after exploring
        board[r][c] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // Start backtracking from each cell in the grid
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (backtrack(board, word, r, c, 0)) // Start backtracking if the first letter matches
                    return true;
            }
        }

        return false;
    }
};
