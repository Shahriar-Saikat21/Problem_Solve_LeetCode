#include<bits/stdc++.h>

using namespace std;
/*
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST 
such that their sum is equal to k, or false otherwise.

Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
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
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;

        vector<int> nums;
        inorder(root, nums);

        int s = 0, l = nums.size() - 1;
        while (s < l) {
            int sum = nums[s] + nums[l];
            if (sum == k)
                return true;
            else if (sum > k)
                l--;
            else
                s++;
        }
        return false;
    }
};

