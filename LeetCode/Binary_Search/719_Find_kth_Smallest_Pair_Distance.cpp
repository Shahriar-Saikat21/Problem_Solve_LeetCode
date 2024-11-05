#include<bits/stdc++.h>

using namespace std;

/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] 
and nums[j] where 0 <= i < j < nums.length.

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Example 2:

Input: nums = [1,1,1], k = 2
Output: 0

Example 3:

Input: nums = [1,6,1], k = 3
Output: 5

*/

class Solution {
public:
    // Count how many pairs under and equal mid
    int countPairs(int propDiff, const vector<int>& nums) {
        int pairCnt = 0, left = 0, right = 0, size = nums.size();
        while (right < size) {
            while (nums[right] - nums[left] > propDiff) left++;
            pairCnt += right - left;
            right++;
        }
        return pairCnt;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int left = 0, right = nums[size - 1] - nums[0];
        int ans = -1;
        while (left <= right) {
            int propDiff = left + (right - left) / 2;
            int propDiffPairCnt = countPairs(propDiff, nums);
            if (propDiffPairCnt < k) {
                left = propDiff + 1;
            } else {
                ans = propDiff;
                right = propDiff - 1;
            }
        }
        return ans;
    }

};