#include<bits/stdc++.h>

using namespace std;

/*
Write an algorithm to determine if a number n is happy.A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which 
does not include 1.Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false

*/

class Solution {
public:
    int getNum(int n){
        int num = 0;
        while(n!=0){
            int d = n%10;
            num += d*d;
            n/=10;
        }
        return num;
    }

    bool isHappy(int n) {
        set<int> s;

        while(n!=1 && !s.count(n)){
            s.insert(n);
            n = getNum(n);
        }
        return n==1;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = process(n);
        }

        return n == 1;
    }
    int process(int n) {
        int res = 0;

        while (n) {
            res += pow((n % 10), 2);
            n /= 10;
        }

        return res;
    }
};