#include<bits/stdc++.h>

using namespace std;
/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).


Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

class Solution {
public:
    double calculatePowRecursive(double x, long n) {

        //Terminating conditions
        if (n == 1)
            return x;
        if (n == 0)
            return 1;
        // for even n
        if (n % 2 == 0)
            return calculatePowRecursive(x * x, n / 2);
        else
            //for odd
            return x * calculatePowRecursive(x, (n - 1));
    }

    double myPow(double x, int n) {
        double ans = 1;
        long N;

        if (n < 0) {
            N = -(long)n;
            return 1.0 / calculatePowRecursive(x, N);
        }

        return calculatePowRecursive(x, n);
    }
};