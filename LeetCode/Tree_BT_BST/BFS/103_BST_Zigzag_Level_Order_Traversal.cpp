#include<bits/stdc++.h>

using namespace std;
/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root==NULL) return result;

        queue<TreeNode*>q;
        int level = 0;
        q.push(root);

        while(!q.empty()){
            vector<int>temp;
            int size = q.size();

            while(size--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
            }

            if(level%2!=0){
                reverse(temp.begin(),temp.end());
            }

            level++;
            result.push_back(temp);
        }
        
        return result;
    }
};