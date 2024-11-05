#include<bits/stdc++.h>

using namespace std;

/*
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:

Input: root = [1]
Output: 0
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

    void leftSum(TreeNode* root, bool is_left, int& ans) {
        if(!root) return;

        if(!root->left && !root->right && is_left) {
            ans += root->val;
        }

        leftSum(root->left, true, ans);
        leftSum(root->right, false, ans);
    }


    public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        leftSum(root, false, ans);

        return ans;
    }
};