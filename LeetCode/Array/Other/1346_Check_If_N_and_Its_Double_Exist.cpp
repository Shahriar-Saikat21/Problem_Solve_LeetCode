#include<bits/stdc++.h>

using namespace std;

/*
Given an array arr of integers, check if there exist two indices i and j such that :
i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 
Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

Example 2:

Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>num;

        for(auto x:arr){
            if(num.count(x*2) || (x%2==0 && num.count(x/2))){
                return true;
            }

            num.insert(x);
        }

        return false;
    }
};