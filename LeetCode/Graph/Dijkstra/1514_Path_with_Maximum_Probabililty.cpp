#include<bits/stdc++.h>

using namespace std;

/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where 
edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing 
that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and 
return its success probability.
If there is no path from start to end, return 0. Your answer will be accepted if it differs from the 
correct answer by at most 1e-5.

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and 
the other has 0.5 * 0.5 = 0.25.

Example 2:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:

Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.

*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //Adjacency list (vertex,weight)
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        //distance array
        vector<double> distance(n, 0.0);
        priority_queue<pair<double,int>> max_heap;

        distance[start_node] = 1.0;
        max_heap.push({1.0,start_node});

        while(!max_heap.empty()){
            auto i = max_heap.top();
            max_heap.pop();

            int vertex = i.second;
            double prob = i.first;

            for(auto x : adj[vertex]){
                int childNode = x.first;
                double childProb = x.second;

                if(prob*childProb > distance[childNode]){
                    distance[childNode] = prob*childProb;
                    max_heap.push({distance[childNode], childNode});
                }
            }

        }

        return distance[end_node];
    }
};

/*
Dijkstra formula: if d(u) + d(u,v) < d(v) then d(v) = d(u) + d(u,v)
Here just reverse the formula as the ques needs to find max probability
*/
