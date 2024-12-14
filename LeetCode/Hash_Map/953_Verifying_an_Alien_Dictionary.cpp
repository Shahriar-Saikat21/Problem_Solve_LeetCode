#include<bits/stdc++.h>

using namespace std;

/*
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. 
The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only 
if the given words are sorted lexicographically in this alien language.

Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) 
According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character
which is less than any other character
*/

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();

        unordered_map<char,int> orderMap;
        for(int i = 0; i<26; i++){
            orderMap[order[i]] = i;
        }

        for(int i=0; i<n-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            for(int j = 0; j<w1.size(); j++){
                if(j==w2.size()) return false;

                if(w1[j]!=w2[j]){
                    if(orderMap[w1[j]]>orderMap[w2[j]]){
                        return false;
                    } 
                    break;
                }
                
            }
        }
        return true;
    }
};