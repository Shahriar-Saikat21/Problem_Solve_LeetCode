#include<bits/stdc++.h>

using namespace std;


/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

*/

//Approach-2 (Bottom Up DP)
//T.C : O(n))
//S.C : O(n)
/*
    We have an array k of first n ugly number. We only know, at the beginning, the first one, which is 1. Then

    k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1. Then we test:

    k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases such as 6, in which we need to forward both pointers of 2 and 3.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n+1);
        //t[i] = ith Ugly number;
        //we will reutrn t[n] = nth ugly number
        
        t[1] = 1; //1st Ugly number
        
        int i2; //i2th Ugly number
        int i3; //i3rd Ugly number
        int i5; //i5th Ugly number
        
        //initially i2th, i3rd and i5th Ugly number point to 1 i.e. first ugly number
        i2 = i3 = i5 = 1;
        
        for(int i = 2; i<=n; i++) {
            int i2th_ugly = t[i2] * 2;
            
            int i3rd_ugly = t[i3] * 3;
            
            int i5th_ugly = t[i5] * 5;
            
            t[i] = min({i2th_ugly, i3rd_ugly, i5th_ugly});
            
            if(t[i] == i2th_ugly)
                i2++;
            
            if(t[i] == i3rd_ugly)
                i3++;
            
            if(t[i] == i5th_ugly)
                i5++;
        }
        
        return t[n];
    }
};


//Approach-1 (Recursion+Memo)
//T.C : O(n * log k), where k is the number range to find the nth ugly number.
//S.C : O(u), where U is the number of distinct values stored in the memoization map mp.
class Solution {
public:
    unordered_map<int, bool> mp;
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        if(n == 1)
            return true;
        
        if(mp.find(n) != mp.end())
            return mp[n];
        
        if(n%2 == 0 && isUgly(n/2))
            return mp[n] = true;
        else if(n%3 == 0 && isUgly(n/3))
            return mp[n] = true;
        else if(n%5 == 0 && isUgly(n/5))
            return mp[n] = true;
        
        return mp[n] = false;
    }
    int nthUglyNumber(int n) {
        mp.clear();
        int num = 1;
        while(n > 0) {
            if(isUgly(num)) {
                n--;
            }
            num++;
        }
        
        return num-1;
    }
};


