#include<bits/stdc++.h>

using namespace std;

/*
Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with 
the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3),
while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 
*/

class Solution {
public:
    void merge(vector<int>& nums,int left,int mid,int right){

        int leftArraySize = mid - left+1;
        int rightArraySize = right-mid;

        int leftArray[leftArraySize+1];
        int rightArray[rightArraySize+1];
    
        for (int i = 0; i < leftArraySize; i++)
        {
            leftArray[i] = nums[left+i];
        }
        leftArray[leftArraySize] = INT_MAX;

        for (int i = 0; i < rightArraySize; i++)
        {
            rightArray[i] = nums[mid+1+i];
        }
        rightArray[rightArraySize] = INT_MAX;

        int leftArrayIndicator = 0;
        int rightArrayIndicator = 0;

        while(left<=right){
            if(leftArray[leftArrayIndicator]<rightArray[rightArrayIndicator]){
                nums[left++] = leftArray[leftArrayIndicator++];
            }else{
                nums[left++] = rightArray[rightArrayIndicator++];
            }
        }

    }

    void mergeSort(vector<int>& nums,int left,int right){
        if(left<right){
            int mid = (left+right)/2;
            mergeSort(nums,left,mid);
            mergeSort(nums,mid+1,right);
            merge(nums,left,mid,right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};