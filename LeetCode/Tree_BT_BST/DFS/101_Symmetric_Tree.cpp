#include<bits/stdc++.h>

using namespace std;

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
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
    bool check(TreeNode* leftRoot,TreeNode* rightRoot){
        if(!leftRoot && !rightRoot) return true;
        if(!leftRoot || !rightRoot || leftRoot->val!=rightRoot->val) return false;
        return check(leftRoot->left,rightRoot->right) && 
                check(leftRoot->right,rightRoot->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left,root->right);
    }
};