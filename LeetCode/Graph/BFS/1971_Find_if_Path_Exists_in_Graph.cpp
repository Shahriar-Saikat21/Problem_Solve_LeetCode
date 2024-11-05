#include<bits/stdc++.h>

using namespace std;

/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] 
denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, 
and no vertex has an edge to itself.
You want to determine if there is a valid path that exists from vertex source to vertex destination.
Given edges and the integers n, source, and destination, return true if there is a valid path from source to 
destination, or false otherwise.

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Example 2:

Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.

*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //Adjacency List
        vector<int>adj[n];
        //Fill the adjacency list with bidirectional edges
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        //BFS
        vector<int>visited(n,0);
        queue<int>q;

        q.push(source);
        visited[source] = 1;

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(auto x: adj[top]){
                if(!visited[x]){
                    visited[x] = 1;
                    q.push(x);
                }
            }
        }

        return visited[destination];
    }
};

/*
Classic BFS Example---
The provided code is an implementation of a breadth-first search (BFS) algorithm to determine if there is a valid
path from a source vertex to a destination vertex in a bi-directional graph represented by its edges. 
Let's break down the intuition behind the code:

Graph Representation: The graph is represented using an adjacency list. An array of vectors adj is created,
where adj[i] stores the neighbors of vertex i. This is populated by iterating through the edges array and adding 
edges to the adjacency list for both directions since it's a bidirectional graph.

Initialization: An array vis is used to mark vertices as visited. Initially, all vertices are marked as 
unvisited (0). A queue q is used for BFS traversal. The source vertex src is pushed onto the queue and marked as 
visited.

BFS Traversal: The main loop continues until the queue is empty. At each iteration, a vertex is dequeued from 
the front of the queue. Then, for each neighbor of this vertex, if it hasn't been visited yet, it is marked as 
visited and added to the queue.

Destination Check: Once BFS traversal is complete, the function checks if the destination vertex dst has been marked 
as visited. If it has, it means there exists a valid path from the source to the destination, and the function 
returns true. Otherwise, it returns false.

Overall, the code explores the graph using BFS, marking visited vertices along the way, and finally checks 
if the destination vertex is reachable from the source vertex. If it is, it returns true; otherwise, 
it returns false.
*/
