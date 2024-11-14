#include<bits/stdc++.h>

using namespace std;

/*
Given a pattern and a string s, find if s follows the same pattern.Here follow means a full match, 
such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 
Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation:
The bijection can be established as:
'a' maps to "dog".
'b' maps to "cat".

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string temp;
        vector<string> ss;

        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                temp.push_back(s[i]);
            } else if (s[i] == ' ') {
                if (!temp.empty()) {
                    ss.push_back(temp);
                    temp.clear();
                }
            }
        }
        if (!temp.empty()) {
            ss.push_back(temp);
        }

        
        map<char, string> mp1;
        map<string, char> mp2;

        if (pattern.length() != ss.size()) {
            return false;
        }

       
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = ss[i];

            //bijection check: 
            // count func check the occurance in map
            if (mp1.count(c)) {
                if (mp1[c] != w) {
                    return false;
                }
            } else {
                mp1[c] = w;
            }

            
            if (mp2.count(w)) {
                if (mp2[w] != c) {
                    return false;
                }
            } else {
                mp2[w] = c;
            }
        }

        return true;
    }
};
