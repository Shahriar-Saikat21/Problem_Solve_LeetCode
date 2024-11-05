#include<bits/stdc++.h>

using namespace std;

/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

*/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        char c = '0';
        int i = 0;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        for (i = 0; i <= min (a.length(), b.length()) - 1; i++){
            if (a[i] != b[i])
            {
                if (c == '1')
                    ans.push_back('0');
                else
                    ans.push_back('1');
            }
            if (a[i] == '0' && b[i] == '0')
            {
                if (c == '1')
                {
                    ans.push_back('1');
                    c = '0';
                }
                else
                    ans.push_back('0');
            }

            if (a[i] == '1' && b[i] == '1')
            {
                if (c == '1')
                    ans.push_back('1');
                else
                {
                    ans.push_back('0');
                    c = '1';
                }
            }
        }

        for (; i < a.length(); i++){
            if (a[i] == '1')
            {
                if (c == '1')
                    ans.push_back('0');
                else
                    ans.push_back('1');
                    
            }
            else
            {
                if (c == '1')
                {
                    ans.push_back('1');
                    c = '0';
                }
                else
                    ans.push_back('0');
            }
        }
        
        for (; i < b.length(); i++){
            if (b[i] == '1')
            {
                if (c == '1')
                    ans.push_back('0');
                else
                    ans.push_back('1');
                    
            }
            else
            {
                if (c == '1')
                {
                    ans.push_back('1');
                    c = '0';
                }
                else
                    ans.push_back('0');
            }
        }

        if (c == '1')
            ans.push_back('1');

        reverse (ans.begin(), ans.end());
        
        return ans;
    }
};