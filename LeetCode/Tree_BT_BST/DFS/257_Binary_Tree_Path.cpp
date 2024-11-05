#include<bits/stdc++.h>

using namespace std;

/*
Given the root of a binary tree, return all root-to-leaf paths in any order.
A leaf is a node with no children.

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:

Input: root = [1]
Output: ["1"]
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
    void traverse(TreeNode* root,string s,vector<string>&result){
        if(root == NULL) return;

        string a = to_string(root->val);

        if(root->left == NULL && root->right == NULL){
            s += a;
            result.push_back(s);
            return;
        }

        traverse(root->left, s+a+"->",result);
        traverse(root->right, s+a+"->",result);

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        traverse(root,"",result);
        return result;
    }
};