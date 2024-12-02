#include<bits/stdc++.h>

using namespace std;
/*
Given a sentence that consists of some words separated by a single space, and a searchWord, 
check if searchWord is a prefix of any word in sentence.
Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. 
If searchWord is a prefix of more than one word, return the index of the first word (minimum index). 
If there is no such word return -1.
A prefix of a string s is any leading contiguous substring of s.

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.

Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, 
but we return 2 as it's the minimal index.

Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
*/

class Solution {
    struct TrieNode{
        int index;
        unordered_map<char,TrieNode*>child;
    };

    TrieNode* root = new TrieNode;

    void insert(string &word, int index){
        TrieNode* cur = root;

        for(int i=0; word[i]!='\0'; i++){
            if(!cur->child.count(word[i])){
                cur->child[word[i]] = new TrieNode;
                cur->child[word[i]]->index = index;
            }
            cur = cur->child[word[i]];
        }
    }

    int search(string &word){
        TrieNode* cur = root;

        for(int i=0; word[i]!='\0'; i++){
            if(!cur->child.count(word[i]))
                return -1;
            cur = cur->child[word[i]];
        }
        return cur->index;
    }

public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int index=1;

        for(int i=0; i<n; i++){
            //Extract a word
            string word="";
            while(i<n and sentence[i]!=' '){
                word.push_back(sentence[i]);
                i++;
            }
            insert(word,index);
            index++;
        }
        return search(searchWord);
    }
};