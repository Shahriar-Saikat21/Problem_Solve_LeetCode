#include<bits/stdc++.h>

using namespace std;


/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. 
These characters divide the square into contiguous regions.
Given the grid grid represented as a string array, return the number of regions.
Note that backslash characters are escaped, so a '\' is represented as '\\'.

Example 1:

Input: grid = [" /","/ "]
Output: 2

Example 2:

Input: grid = [" /","  "]
Output: 1

Example 3:

Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

*/

class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}} ;
    
    void dfs(int i, int j, vector<vector<int>> &na, vector<vector<bool>> &vis) {
        vis[i][j] = 1 ; 
        for(int k = 0 ; k< 4 ; k++) {
            int r = i + dir[k][0], c = j + dir[k][1] , n = na.size() ; 
            if(r < 0 or c < 0 or r>=n or c >=n or na[r][c] != 0)
                continue ; 
            if(!vis[r][c])
                dfs(r,c,na,vis) ; 
        }
    }
    
    int regionsBySlashes(vector<string>& a) {
        int n = a.size()*3 , m = a.size() ; 
        vector<vector<int>> na(n, vector<int>(n, 0)) ; 
        vector<vector<bool>> vis(n, vector<bool>(n, 0)) ; 
        for(int i =0 ; i < m ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(a[i][j] == '/') {
                    na[i*3][j*3 + 2] = 1 ; 
                    na[i*3 + 1][j*3 + 1] = 1 ; 
                    na[i*3 + 2][j*3] = 1 ; 
                }
                else if(a[i][j] == '\\') {
                    na[i*3][j*3] = 1 ; 
                    na[i*3 + 1][j*3 + 1] = 1 ; 
                    na[i*3 + 2][j*3 + 2] = 1 ;
                }
            }
        }
        int ct = 0 ; 
        for(int i =0 ; i < n ; i++) {
            for(int j =0 ; j < n ; j++) {
                if(na[i][j] == 0 and !vis[i][j]){
                    dfs(i, j, na, vis) ; 
                    ct++ ; 
                }
            }
        }
        return ct ; 
    }
};