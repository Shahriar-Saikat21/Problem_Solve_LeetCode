#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int>result;

        int i = 0, j = 0;

        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                result.push_back(nums1[i++]);
            }else{
                result.push_back(nums2[j++]);
            }
        }

        while(i<n1){
            result.push_back(nums1[i++]);
        }

        while(j<n2){
            result.push_back(nums2[j++]);
        }

        int v = result.size();

        if(v%2==0){
            return (result[v/2]+result[v/2-1])/2.0;
        }else{
            return result[v/2];
        }
    }
};