#include<bits/stdc++.h>

using namespace std;

/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]
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
    void inorder(TreeNode* root, vector<int>&result){
        if(root == NULL) return;

        inorder(root->left,result);
        result.push_back(root->val);
        inorder(root->right,result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        inorder(root,result);
        return result;
    }
};