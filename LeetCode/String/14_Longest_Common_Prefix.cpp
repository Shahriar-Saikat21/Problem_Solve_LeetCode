#include<bits/stdc++.h>

using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = strs[0];
        int length = prefix.length();
        for(int i=1;i<strs.size();i++){
            string s=strs[i];
            while(length > s.length() || prefix != s.substr(0, length)){
                length--;
                if(length == 0){
                    return "";
                }
                prefix = prefix.substr(0, length);
            }
        }
        return prefix;
    }
};