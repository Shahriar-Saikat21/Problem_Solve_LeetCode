#include<bits/stdc++.h>

using namespace std;

/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:

Input: root = [1,2,3]
Output: [1,3]
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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int>result;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int maxVal = INT_MIN;
            int size = q.size();

            while(size--){
                TreeNode* temp = q.front();
                q.pop();

                maxVal = max(maxVal,temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            result.push_back(maxVal);
        }

        return result;

    }
};