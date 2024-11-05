#include<bits/stdc++.h>

using namespace std;

/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n),right(n);       
        stack<int> mystack;

        //Find left boundary for each histogram
        for(int i=0;i<n;++i){
            if(mystack.empty()){   
                left[i] = 0;   
                mystack.push(i);    
            }else{
                while(!mystack.empty() && heights[mystack.top()]>=heights[i]){
                    mystack.pop();
                }        
                left[i] = mystack.empty()?0:mystack.top()+1;
                mystack.push(i);
            }
        }

        //Clear stack
        while(!mystack.empty()){
            mystack.pop();
        } 

        //Find right boundary for each histogram   
        for(int i=n-1;i>=0;--i){
            if(mystack.empty()){   
                right[i] = n-1; mystack.push(i);    
            }
            else{
                while(!mystack.empty() and heights[mystack.top()]>=heights[i]){
                    mystack.pop();
                }    
                right[i] = mystack.empty()?n-1:mystack.top()-1;
                mystack.push(i);
            }
        }
        
        //Stores max_area
        int mx_area = 0;    
        for(int i=0;i<n;++i)
            mx_area = max(mx_area,heights[i]*(right[i]-left[i]+1));
        return mx_area;
    }
};