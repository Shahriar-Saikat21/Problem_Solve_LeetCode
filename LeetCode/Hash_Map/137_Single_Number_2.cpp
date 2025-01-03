#include<bits/stdc++.h>

using namespace std;

/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. 
Find the single element and return it.You must implement a solution with a linear runtime complexity and 
use only constant extra space.

Example 1:

Input: nums = [2,2,3,2]
Output: 3

Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
 
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>m;

        for(int x:nums){
            m[x]++;
        }

        for(auto x : m){
            if(x.second == 1) return x.first;
        }

        return -1;
    }
};
