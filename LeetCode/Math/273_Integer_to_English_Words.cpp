#include<bits/stdc++.h>

using namespace std;

/*
Convert a non-negative integer num to its English words representation.

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 
Constraints:
0 <= num <= 231 - 1

*/

class Solution {
public:
    string numberToWords(int num) {
        vector<string> belowTen = { "", "One", "Two", "Three",       "Four", "Five", "Six", "Seven", "Eight", "Nine" };
        vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
        vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
        
        if (num == 0) {
            return "Zero";
        }

        if (num < 10) {
            return belowTen[num];
        }

        if (num < 20) {
            return belowTwenty[num - 10];
        }

        if (num < 100) {
            return belowHundred[num / 10] + (num % 10 != 0 ? " " + belowTen[num % 10] : "");
        }

        if (num < 1000) {
            return belowTen[num / 100] + " Hundred" + (num % 100 != 0 ? " " + numberToWords(num % 100) : "");
        }

        if (num < 1000000) {
            return numberToWords(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + numberToWords(num % 1000) : "");
        }

        if (num < 1000000000) {
            return numberToWords(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + numberToWords(num % 1000000) : "");
        
        }
        return numberToWords(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + numberToWords(num % 1000000000) : "");

    }
};

/*
Approach
To solve the problem of converting an integer to its English words representation, you can follow these steps:

Understand the Problem:
You need to convert a number into its corresponding English words.
Numbers can range from 0 to 2,147,483,647.

Break Down the Problem:
Numbers can be categorized into different segments:

Numbers below 10
Numbers between 10 and 19
Numbers between 20 and 99
Numbers between 100 and 999
Numbers in thousands, millions, and billions.
Create Helper Arrays:
Define arrays to map numbers to their English words:

vector<string> belowTen = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
vector<string> belowTwenty = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
vector<string> belowHundred = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
Define the Base Cases:
If the number is 0, return "Zero".
Recursive Breakdown:

Use recursion to handle large numbers by breaking them into smaller segments (thousands, millions, billions).

Construct the Words:
For numbers below 100, handle units and tens.
For numbers between 100 and 999, handle hundreds.
For numbers between 1000 and 999,999, use "Thousand".
For numbers between 1,000,000 and 999,999,999, use "Million".
For numbers between 1,000,000,000 and 2,147,483,647, use "Billion".

Handling Base Cases:
Directly handle cases for numbers below 10, 20, 100, and 1000 with specific logic.

Recursive Calls:
For numbers in the thousands, millions, and billions, recursively call the function to break down the problem into manageable chunks.
Combining Results:

Combine results from recursive calls with appropriate labels ("Thousand", "Million", "Billion") and handle spacing between words.
*/