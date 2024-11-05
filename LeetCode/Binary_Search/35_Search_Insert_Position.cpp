#include<bits/stdc++.h>

using namespace std;


/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,mid,high = nums.size()-1;

        if(nums[high]<target) return high+1;

        while(low<=high){
            mid = low+(high-low)/2;

            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

        if ( target > nums [mid]  && target < nums [mid+1]){
            return mid+1;
        }else{
            return mid;
        }
    }
};