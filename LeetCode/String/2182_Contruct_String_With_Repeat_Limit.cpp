#include<bits/stdc++.h>

using namespace std;

/*
You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the 
characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all 
characters from s.Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, 
string a has a letter that appears later in the alphabet than the corresponding letter in b. 
If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically 
larger one.

Example 1:

Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, 
so it is not a valid repeatLimitedString.

Example 2:

Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, 
so it is not a valid repeatLimitedString.
 

*/

class Solution {
public:
    string repeatLimitedString(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) pq.push({'a' + i, freq[i]});
        }
        
        string result;
        while (!pq.empty()) {
            auto [ch, count] = pq.top(); pq.pop();
            int used = min(k, count);
            result.append(used, ch);
            count -= used;

            if (count > 0) {
                if (pq.empty()) break;
                auto [nextCh, nextCount] = pq.top(); pq.pop();
                result += nextCh;
                nextCount--;

                if (nextCount > 0) pq.push({nextCh, nextCount});
                pq.push({ch, count});
            }
        }
        return result;
    }
};