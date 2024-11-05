#include<bits/stdc++.h>

using namespace std;


/*
Given an integer x, return true if x is a  palindrome and false otherwise.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. 
Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


*/

class Solution {
public:
    bool isPalindrome(int x) {
        unsigned int result = 0;
        unsigned int temp = x;

        if(x<0) return false;

        while(temp>0){
            int y = temp % 10;
            result = (result*10) + y;
            temp/=10;
        }

        if(result==x) return true;

        return false;
    }
};