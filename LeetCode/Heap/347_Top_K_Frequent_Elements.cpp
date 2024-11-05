#include<bits/stdc++.h>

using namespace std;

/*
Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]


*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>>pq;

        for(auto i:mp){
            pq.push({i.second, i.first});
        }

        while(k!=0){
          ans.push_back(pq.top().second);
          pq.pop();
          k--;
        }

        return ans;
    }
};