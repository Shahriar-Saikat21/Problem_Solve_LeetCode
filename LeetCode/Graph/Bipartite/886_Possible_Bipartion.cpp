#include<bits/stdc++.h>

using namespace std;

/*
We want to split a group of n people (labeled from 1 to n) into two groups of any size. 
Each person may dislike some other people, and they should not go into the same group.
Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled 
ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: The first group has [1,4], and the second group has [2,3].

Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.
 
Bipartite Graph : Vertices can be divided into two disjoint sets;A bipartite graph can be partitioned into two sets 
of vertices, with no edges between vertices
 
*/

class Solution {
public:
    bool bfs(int start, vector<vector<int>>& graph, vector<int>& visited) {
        queue<int> q;
        q.push(start);
        visited[start] = 0; // Assign the first group (0)

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbor : graph[node]) {
                if (visited[neighbor] == -1) {
                    // Assign the opposite group
                    visited[neighbor] = !visited[node];
                    q.push(neighbor);
                } else if (visited[neighbor] == visited[node]) {
                    // Conflict detected
                    return false;
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // Create an adjacency list for the graph
        vector<vector<int>> graph(n + 1);
        for (auto& dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }

        // Initialize the visited vector with -1 (unvisited)
        vector<int> visited(n + 1, -1);

        // Traverse each node to handle disconnected components
        for (int i = 1; i <= n; i++) {
            if (visited[i] == -1) {
                if (!bfs(i, graph, visited)) {
                    return false;
                }
            }
        }

        return true;
    }
};
