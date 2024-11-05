#include<bits/stdc++.h>

using namespace std;
/*
Given the root of a Binary Search Tree (BST), return the minimum absolute difference between 
the values of any two different nodes in the tree.

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

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
    int prev = INT_MAX;
    int ans = INT_MAX;

    void inOrder(TreeNode* root){
        if(root == NULL) return;

        inOrder(root->left);

        ans = min(ans,abs(root->val - prev));
        prev = root->val;

        inOrder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return ans;
    }
};