#include<bits/stdc++.h>

using namespace std;


/*
A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

 

Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
Example 3:

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.

*/
//Time Complexity - O(n), Space Complexity - O(n)
class Solution1 {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOne = 0;

        //Count 1
        for(auto x:nums){
            if(x==1) totalOne++;
        }

        //Make circular array
        vector<int>temp(2*n);
        for(int i=0; i< 2*n; i++){
            temp[i] = nums[i%n];
        }

        //sliding window approch
        int i = 0, j=0;

        int currOne=0, maxOne=0;

        while(j < 2*n){
            // add 1 at right window if
            if(temp[j] == 1){
                currOne++;
            }

            if(j-i+1 > totalOne){
                currOne -= temp[i]; //exclude 0,1 from left window
                i++; // increase left window
            }

            maxOne = max(maxOne,currOne);
            j++;
        }

        return totalOne-maxOne;
    }
};

//Time Complexity - O(n), Space Complexity - O(1)
class Solution2 {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOne = 0;

        //Count 1
        for(auto x:nums){
            if(x==1) totalOne++;
        }

        //sliding window approch
        int i = 0, j=0;

        int currOne=0, maxOne=0;

        while(j < 2*n){
            // add 1 at right window if
            if(nums[j%n] == 1){
                currOne++;
            }

            if(j-i+1 > totalOne){
                currOne -= nums[i%n]; //exclude 0,1 from left window
                i++; // increase left window
            }

            maxOne = max(maxOne,currOne);
            j++;
        }

        return totalOne-maxOne;
    }
};