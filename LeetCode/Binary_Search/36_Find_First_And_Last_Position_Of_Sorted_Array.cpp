#include<bits/stdc++.h>

using namespace std;


/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int index1 = -1, index2 = -1;
        int n = nums.size();
        int start = 0, end = n-1, mid;
       

        while(start <= end){
            mid = start + (end-start)/2;
            if(target == nums[mid]){
                index1 = mid;
                end = mid-1;
            }else if(target < nums[mid]){
                end = mid-1;
            }else start = mid+1;
        }

        start = 0; end = n-1; mid = start + (end-start)/2;
        while(start <= end){
            mid = start + (end-start)/2;
            if(target == nums[mid]){
                index2 = mid;
                start = mid+1;
            }else if(target < nums[mid]){
                end = mid-1;
            }else start = mid+1;
        }

        ans.push_back(index1);
        ans.push_back(index2);
        return ans;
    }
};