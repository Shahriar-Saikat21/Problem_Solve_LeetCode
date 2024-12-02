#include<bits/stdc++.h>

using namespace std;
/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and 
retrieve keys in a dataset of strings. There are various applications of this data structure, 
such as autocomplete and spellchecker.
Implement the Trie class:
->Trie() Initializes the trie object.
->void insert(String word) Inserts the string word into the trie.
->boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), 
  and false otherwise.
->boolean startsWith(String prefix) Returns true if there is a previously inserted string word that 
  has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
*/

class Trie {
    struct TrieNode{
        char val;
        int count;    // is there any string having this chat
        int endHere;  // is it last char of a string
        TrieNode* child[26];
    };

    TrieNode* root;

    TrieNode* getNode(int index){
        TrieNode* newNode = new TrieNode;

        newNode->val = 'a' + index;
        newNode->count = newNode->endHere = 0;

        for(int i=0; i<26; i++){
            newNode->child[i] = NULL;
        }

        return newNode;
    }

public:
    Trie() {
        //root is initialized by '/'
        root = getNode('/'-'a');
    }
    
    void insert(string word) {
        TrieNode* cur = root;

        int index;

        for(int i=0; word[i]!='\0'; i++){
            index = word[i] - 'a';
            if(cur->child[index] ==NULL){
                cur->child[index] = getNode(index);
            }
            cur->child[index]->count++;
            cur = cur->child[index];
        }
        cur->endHere++;
    }
    
    bool search(string word) {
        TrieNode* cur = root;

        int index;

        for(int i=0; word[i]!='\0'; i++){
            index = word[i] - 'a';
            if(cur->child[index] ==NULL){
                return false;
            }
            cur = cur->child[index];
        }

        return (cur->endHere > 0);
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;

        int index;

        for(int i=0; prefix[i]!='\0'; i++){
            index = prefix[i] - 'a';
            if(cur->child[index] ==NULL){
                return false;
            }
            cur = cur->child[index];
        }

        return (cur->count > 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */