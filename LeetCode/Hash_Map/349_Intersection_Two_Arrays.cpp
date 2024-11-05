#include<bits/stdc++.h>

using namespace std;

/*
Given two integer arrays nums1 and nums2, return an array of their 
intersection
. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.


*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        unordered_map<int,int>mp;
        set<int>s;

        for(int i=0; i<nums1.size(); i++){
            mp[nums1[i]]++;
        }

        for(int i=0; i<nums2.size(); i++){
            if(mp.find(nums2[i])!=mp.end()){
                s.insert(nums2[i]);
            }
        }

        for(auto i : s){
            result.push_back(i);
        }


        return result;
    }
};

class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        for(auto i:nums1){
            m[i]=1;
        }
        vector<int>result;
        for(auto x:nums2){
            if(m[x]==1){
                result.push_back(x);
                m[x]=0;
            }
        }
        return result;
    }
};