#include<bits/stdc++.h>

using namespace std;


/*
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.



*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        set<char>st;
        int left = 0, right = 0;
        
        while(right< s.size()){
            auto it = st.find(s[right]);
            if(it == st.end()){
                result = max(result,right-left+1);
                st.insert(s[right]);
                right++;
            }else{
                st.erase(s[left]);
                left++;
            }
        }
        
        return result;
    }
};