#include<bits/stdc++.h>

using namespace std;

/*
Given a string n representing an integer, return the closest integer (not including itself), 
which is a palindrome. If there is a tie, return the smaller one.
The closest is defined as the absolute difference minimized between two integers.

Example 1:

Input: n = "123"
Output: "121"

Example 2:

Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.

Constraints:

-1 <= n.length <= 18
-n consists of only digits.
-n does not have leading zeros.
-n is representing an integer in the range [1, 1018 - 1].

*/

class Solution {
public:
    string nearestPalindromic(string numberStr) {
        long long number = stoll(numberStr);
        if (number <= 10) return to_string(number - 1);
        if (number == 11) return "9";

        int length = numberStr.length();
        long long leftHalf = stoll(numberStr.substr(0, (length + 1) / 2));
        
        vector<long long> palindromeCandidates(5);
        palindromeCandidates[0] = generatePalindromeFromLeft(leftHalf - 1, length % 2 == 0);
        palindromeCandidates[1] = generatePalindromeFromLeft(leftHalf, length % 2 == 0);
        palindromeCandidates[2] = generatePalindromeFromLeft(leftHalf + 1, length % 2 == 0);
        palindromeCandidates[3] = pow(10, length - 1) - 1;
        palindromeCandidates[4] = pow(10, length) + 1;

        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;

        for (long long candidate : palindromeCandidates) {
            if (candidate == number) continue;
            long long difference = abs(candidate - number);
            if (difference < minDifference || (difference == minDifference && candidate < nearestPalindrome)) {
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }

        return to_string(nearestPalindrome);
    }

private:
    long long generatePalindromeFromLeft(long long leftHalf, bool isEvenLength) {
        long long palindrome = leftHalf;
        if (!isEvenLength) leftHalf /= 10;
        while (leftHalf > 0) {
            palindrome = palindrome * 10 + leftHalf % 10;
            leftHalf /= 10;
        }
        return palindrome;
    }
};

/*
Palindrome should be---
1.The palindrome formed by the left half of the number as is.
2.The palindrome formed by decrementing the left half of the number.
3.The palindrome formed by incrementing the left half of the number.
4.The number with all 9's that has one digit less than the input.
5.The number with all 0's and 1's at the ends that has one digit more than the input.

-If the number is 1-10, the closest palindrome is always the previous number. For example, for 6, it's 5; for 10, it's 9.
-If the number is 11, the closest palindrome is 9.
*/