#include<bits/stdc++.h>

using namespace std;
/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge 
connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass 
through the root.The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.

Example 1:

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/

//Definition for a binary tree node.
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
    int max_sum = INT_MIN;

    int max_gain(TreeNode* node) {
        if (!node) return 0;

        // Maximum gain from left and right subtrees
        int left_gain = max(max_gain(node->left), 0);
        int right_gain = max(max_gain(node->right), 0);

        // Price of the new path
        int price_new_path = node->val + left_gain + right_gain;

        // Update global max_sum if the new path is better
        max_sum = max(max_sum, price_new_path);

        // Return the max gain if the path continues through the parent
        return node->val + max(left_gain, right_gain);
    }

    int maxPathSum(TreeNode* root) {
        max_gain(root);
        return max_sum;
    }
};