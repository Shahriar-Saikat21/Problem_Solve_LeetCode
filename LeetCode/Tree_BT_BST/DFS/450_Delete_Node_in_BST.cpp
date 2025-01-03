#include<bits/stdc++.h>

using namespace std;
/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.Basically, the deletion can be divided into two stages:
-Search for a node to remove.
-If the node is found, delete the node.

Example 1:

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:

Input: root = [], key = 0
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
    int minValue(TreeNode* root){
        int minVal = root->val;
        while(root->left != NULL){
            minVal = root->left->val;
            root = root->left;
        }
        return minVal;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            // case 1 : leaf node
            if(root->left==NULL && root->right==NULL) return NULL;
            // case 2 : node with one child
            if(root->left==NULL || root->right==NULL) {
                if(root->left != NULL) return root->left;
                else return root->right; 
            }
            // case 3 : node with 2 child
            if(root->left!=NULL && root->right!=NULL) {
                // replace the root with inorder successor of right side min val
                root->val = minValue(root->right); 
                //Delete the right most min value
                root->right = deleteNode(root->right,root->val);
            }
        } 
        // go left
        else if(root->val > key) root->left=deleteNode(root->left,key);
        // go right
        else root->right=deleteNode(root->right,key);

        return root;
    }
};