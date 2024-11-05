#include<bits/stdc++.h>

using namespace std;
/*
Given a string s, reverse the order of characters in each word within a sentence while still 
preserving whitespace and initial word order.

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"

*/

class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.length();
       
        for(int j=0;j<=n;j++)
        {
            if(s[j]==' ' || j==n)
            {
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
             }
 
        }

        return s;
    }
};

class Solution2 {
public:
    string reverseWords(string s) {
        stack<char> st;
        string result = "";
        for (char c : s) {
            if (c != ' ') {
                st.push(c);
            } else {
                while (!st.empty()) {
                    result += st.top();
                    st.pop();
                }
                result += ' ';
            }
        }
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};