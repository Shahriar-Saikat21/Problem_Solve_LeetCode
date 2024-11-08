#include<bits/stdc++.h>

using namespace std;

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all 
the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in 
a 32-bit integer.You must write an algorithm that runs in O(n) time and without using the division operation.


Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Explaination:

Arr : 1,2,3,4
Left: 1,2,6,24
Right: 24,24,12,4
ans = all left * all right except ith index

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]*nums[i];
        }
        vector<int> suffix(n);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]*nums[i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i]=suffix[i+1];
            }
            else if(i==n-1){
                ans[i]=prefix[i-1];
            }
            else{
                ans[i]=prefix[i-1]*suffix[i+1];
            }
        }
        return ans;
    }
};