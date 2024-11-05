#include<bits/stdc++.h>

using namespace std;
/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of 
all the values of the nodes in the tree.

Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
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
    void traverse(TreeNode* root,priority_queue<int,vector<int>,greater<int>>&pq){
        if(root == NULL) return;
        traverse(root->left,pq);
        pq.push(root->val);
        traverse(root->right,pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        traverse(root,pq);
        int result = INT_MAX;
        for(int i=1; i<=k; i++){
            result = pq.top();
            pq.pop();
        }
        return result;
    }
};

class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans, cnt = 0;
        inorderTra(root,k,cnt,ans);
        return ans;
    }
    void inorderTra(TreeNode* root, int k, int &cnt, int &ans){
        if(root==NULL) return;
        inorderTra(root->left,k,cnt,ans);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        inorderTra(root->right,k,cnt,ans);
    }
};