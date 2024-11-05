#include<bits/stdc++.h>

using namespace std;

/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such 
that adding up all the values along the path equals targetSum. A leaf is a node with no children.

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:

Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

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
    bool solve(TreeNode* &root, int &targetSum, int sum) {
        if (root == NULL) return false;
        sum = sum + root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum)
                return true;
            else
                return false;
        }

        bool leftAns = solve(root->left, targetSum, sum);
        bool rightAns = solve(root->right, targetSum, sum);
        
        return leftAns || rightAns;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        int sum = 0;
        bool ans = solve(root, targetSum, sum);
        return ans;
    }
};