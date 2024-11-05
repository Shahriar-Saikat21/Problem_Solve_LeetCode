#include<bits/stdc++.h>

using namespace std;

/*
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "hello"
Output: "holle"

Example 2:

Input: s = "leetcode"
Output: "leotcede"

*/

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        string v = "aeouiAEIOU";
        while(i < j) {
            if(v.find(s[i]) != string::npos && v.find(s[j]) != string::npos) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(v.find(s[j]) != string::npos){
                i++;
            }
            else j--;
        }
        return s;
    }
};