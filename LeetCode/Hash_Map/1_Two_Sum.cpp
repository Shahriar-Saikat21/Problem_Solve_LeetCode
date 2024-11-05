#include<bits/stdc++.h>

using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that 
they add up to target.You may assume that each input would have exactly one solution, and you may not 
use the same element twice.You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Input: nums = [3,2,4], target = 6
Output: [1,2]

Input: nums = [3,3], target = 6
Output: [0,1]

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        unordered_map<int,int> mp;
        mp[nums[0]] = 0;

        for(int i = 1; i<nums.size(); i++){
            int temp = target - nums[i];
            if(mp.find(temp) != mp.end()){
                result.push_back(mp[temp]);
                result.push_back(i);
                return result;
            }else{
                mp[nums[i]] = i;
            }            
        }
        return result;       
    }
};