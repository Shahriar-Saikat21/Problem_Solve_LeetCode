#include<bits/stdc++.h>

using namespace std;


/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = 0;
        int current_sum = 0;
        int min_length = INT_MAX;

        while (end < n) {
            current_sum += nums[end];
            end++;
            
            while (current_sum >= target) {
                min_length = min(min_length, end - start);
                current_sum -= nums[start];
                start++;
            }
        }
        return (min_length == INT_MAX) ? 0 : min_length;
    }
};