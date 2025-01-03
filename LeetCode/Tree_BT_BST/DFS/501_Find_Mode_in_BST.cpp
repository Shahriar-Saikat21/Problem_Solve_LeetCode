#include<bits/stdc++.h>

using namespace std;
/*
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) 
(i.e., the most frequently occurred element) in it.
If the tree has more than one mode, return them in any order.
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 
Example 1:

Input: root = [1,null,2,2]
Output: [2]

Example 2:

Input: root = [0]
Output: [0]
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void dfs(TreeNode* root, unordered_map<int,int>&result){
        if(root!=NULL){
            dfs(root->left,result);
            result[root->val]++;
            dfs(root->right,result);
        }
    }

    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        unordered_map<int,int>result;
        dfs(root,result);
        int maxValue = 0;
        for(auto i:result){
            if(i.second>maxValue){
                ans.clear();
                maxValue =i.second;
                ans.push_back(i.first);
            }else if(i.second==maxValue){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};