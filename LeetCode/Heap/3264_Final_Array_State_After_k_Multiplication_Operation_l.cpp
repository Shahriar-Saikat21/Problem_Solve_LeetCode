#include<bits/stdc++.h>

using namespace std;

/*
You are given an integer array nums, an integer k, and an integer multiplier.You need to perform k operations 
on nums. In each operation:
->Find the minimum value x in nums. If there are multiple occurrences of the minimum value, 
select the one that appears first.
->Replace the selected minimum value x with x * multiplier.

Return an integer array denoting the final state of nums after performing all k operations.

Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2
Output: [8,4,6,5,6]
Explanation:
Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]

Example 2:

Input: nums = [1,2], k = 3, multiplier = 4
Output: [16,8]
Explanation:
Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]

*/

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(int i=0;i<n;i++){
            minHeap.push({nums[i],i});
        }

        while(k){
            auto [value,index] = minHeap.top();
            nums[index] = nums[index]*multiplier;
            minHeap.pop();
            minHeap.push({nums[index],index});
            k--;
        }
        return nums;
    }
};

class Solution {
public:
    #define pp pair<int,int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pp,vector<pp>, greater<pp>>pq;
        int size = nums.size();

        for(int i=0; i<size; i++){
            pq.push({nums[i],i});
        }

        while(k--){
            auto [x,j] = pq.top();
            pq.pop();
            pq.push({x*multiplier,j});
        }

        while(!pq.empty()){
            auto [x,i]=pq.top();
            pq.pop();
            nums[i]=x;
        }
        return nums;
    }
};