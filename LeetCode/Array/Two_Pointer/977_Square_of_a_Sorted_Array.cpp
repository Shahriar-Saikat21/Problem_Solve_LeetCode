#include<bits/stdc++.h>

using namespace std;

/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number 
sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0, right = nums.size() - 1;
        int index = nums.size() - 1;

        while (left <= right)
        {
            int lSquare = nums[left] * nums[left];
            int rSquare = nums[right] * nums[right];

            if (lSquare >= rSquare)
            {
                result[index] = lSquare;
                left++;
            }
            else
            {
                result[index] = rSquare;
                right--;
            }
            index--;
        }
        return result;
    }
};

class Solution_Two {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;

        for(auto x: nums){
            pq.push(x * x);
        }

        vector<int>result;

        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};

class Solution_Three {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());

        return nums;
    }
};