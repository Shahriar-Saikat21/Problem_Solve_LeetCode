#include<bits/stdc++.h>

using namespace std;
/*
Given the root of a complete binary tree, return the number of the nodes in the tree.According to Wikipedia, 
every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last 
level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:

Input: root = []
Output: 0

Example 3:

Input: root = [1]
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
    void traverse(TreeNode* root, int &count){
        if(root == NULL) return ;
        count++;
        traverse(root->left,count);
        traverse(root->right,count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        traverse(root,count);
        return count;
    }
};

