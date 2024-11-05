#include<bits/stdc++.h>

using namespace std;

/*
You are given a sorted array consisting of only integers where every element appears exactly twice, 
except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid % 2 == 1) {
                mid--;
            }
            if (nums[mid] != nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 2;
            }
        }
        return nums[left];
    }
};

/*
Intuition of this Problem:
Since every element in the sorted array appears exactly twice except for the single element, 
we know that if we take any element at an even index (0-indexed), the next element should be the same. 
Similarly, if we take any element at an odd index, the previous element should be the same. 
Therefore, we can use binary search to compare the middle element with its adjacent elements to determine 
which side of the array the single element is on.
If the middle element is at an even index, then the single element must be on the right side of the array, 
since all the elements on the left side should come in pairs. Similarly, if the middle element is at an odd index, 
then the single element must be on the left side of the array.
We can continue this process by dividing the search range in half each time, until we find the single element.
*/