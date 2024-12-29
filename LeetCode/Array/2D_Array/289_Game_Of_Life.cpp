#include<bits/stdc++.h>

using namespace std;


/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by 
the British mathematician John Horton Conway in 1970."
The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or 
dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the 
following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.

Given the current state of the board, update the board to reflect its next state.
Note that you do not need to return anything.

Example 1:

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:

Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
 
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // live cell = 1   // dead cell = 0
        // if 1: <two 1 or >three 1 -> 0
        // if 0: three 1 -> 1
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> count_live(m, vector<int>(n,0));
        // count 1 for all directions
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){ // update 8 directions 
                    if(i>0) count_live[i-1][j]++; // left
                    if(i<m-1) count_live[i+1][j]++; // right
                    if(j>0) count_live[i][j-1]++; // up
                    if(j<n-1) count_live[i][j+1]++; // down
                    if(i>0 && j>0) count_live[i-1][j-1]++; // north-west
                    if(i>0 && j<n-1) count_live[i-1][j+1]++; // north-east
                    if(i<m-1 && j>0) count_live[i+1][j-1]++; // south-west
                    if(i<m-1 && j<n-1) count_live[i+1][j+1]++; // south-east
                }
            }
        }
        // update state as per rules given in problem
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){  // currently live state [1]
                    if(count_live[i][j] < 2 || count_live[i][j] > 3) board[i][j] =0;
                } else{ // currently dead state [0]
                    if(count_live[i][j] == 3) board[i][j] = 1;
                }
            }
        }
    }
};