#include<bits/stdc++.h>

using namespace std;


/*
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the
number of points you can get from the matrix. To gain points, you must pick one cell in each row. Picking the 
cell at coordinates (r, c) will add points[r][c] to your score. However, you will lose points if you pick a cell 
too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 
(where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from 
your score.
Return the maximum number of points you can achieve.
abs(x) is defined as:
x for x >= 0.
-x for x < 0.
 
Example 1:

Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.

Example 2:

Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.

*/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        //dynamic programming
        int m = points.size(), n = points[0].size();
        long long currMax;
        vector<long long> maxPoints(n), rightRow(n);
        for(auto row: points){
            currMax = 0;

            //Calculate maximum points from the right
            //We do this as we need to change the value of maxPoints[j]
            for(int j = n-1; j >= 0; j--){
                currMax = max(currMax, maxPoints[j]);
                rightRow[j] = currMax--;
            }

            currMax = 0; //Maximum points from the left
            for(int j = 0; j < n; j++){
                currMax = max(currMax, maxPoints[j]);
                //Consider maximum points possible if we pick 
                //the cell of index j of current row
                maxPoints[j] = max(currMax--, rightRow[j]) + row[j];
            }
        }

        // return maximum possible amount of points
        return *max_element(maxPoints.begin(), maxPoints.end());
    }
};

class Solution2 {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int cols = points[0].size();
        vector<long long> currentRow(cols), previousRow(cols);
        
        for (auto& row : points) {
            // runningMax holds the maximum value generated in the previous iteration of each loop
            long long runningMax = 0;

            // Left to right pass
            for (int col = 0; col < cols; ++col) {
                runningMax = max(runningMax - 1, previousRow[col]);
                currentRow[col] = runningMax;
            }
            
            runningMax = 0;
            // Right to left pass
            for (int col = cols - 1; col >= 0; --col) {
                runningMax = max(runningMax - 1, previousRow[col]);
                currentRow[col] = max(currentRow[col], runningMax) + row[col];
            }
            
            // Update previousRow for next iteration
            previousRow = currentRow;
        }
        
        // Find maximum points in the last row
        long long maxPoints = 0;
        for (int col = 0; col < cols; ++col) {
            maxPoints = max(maxPoints, previousRow[col]);
        }
        
        return maxPoints;
    }
};