#include<bits/stdc++.h>

using namespace std;

/*
Given a n-ary tree, find its maximum depth.The maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node.Nary-Tree input serialization is represented in their level 
order traversal, each group of children is separated by the null value (See examples).

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: 3

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5
 
*/

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class SolutionDFS {
public:
    int dfs(Node* root){
        if(root==NULL) return 0;
        int depth = 0;
        for(auto x: root->children){
            depth = max(depth,dfs(x)+1);
        }
        return depth;
    }

    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        return dfs(root) + 1;
    }
};

class SolutionBFS {
public:
    int maxDepth(Node* root) {
        if(!root) return 0;
        int level=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            level++;
            int s=q.size();
            for(int i=0;i<s;i++){
                Node* temp = q.front();
                q.pop();
                int size = temp->children.size();
                for(int j=0;j<size;j++){
                    q.push(temp->children[j]);
                }        
            }
        }  

        return level; 
    }
};