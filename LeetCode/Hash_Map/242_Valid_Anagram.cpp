#include<bits/stdc++.h>

using namespace std;

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int l = t.length();

        if(n != l) {
           return false;
        }

        unordered_map<char,int> m;


        for(int i = 0 ; i < n ; i++) {
            m[s[i]]++;
        }

        for(int i = 0 ; i < t.length() ; i++) {
            if(m.find(t[i]) == m.end() || m[t[i]] == 0) {
                return 0;
            }
            m[t[i]]--;
        }


        return true;
    }
};
