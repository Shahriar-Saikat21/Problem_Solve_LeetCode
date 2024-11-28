#include<bits/stdc++.h>

using namespace std;

/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents 
a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance 
is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along 
that path.

Example 1:

Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 
since it has the greatest number.

Example 2:

Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.

*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        int min_count = INT_MAX, ans_city;

        // Iterate over each city to apply Dijkstra's algorithm
        for(int i = 0; i < n; i++) {
            vector<int> dist(n, INT_MAX); // Distance array
            dist[i] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
            pq.push({0, i});

            // Dijkstra's algorithm to find shortest paths
            while(!pq.empty()) {
                auto [wt, node] = pq.top(); // Get the node with the smallest distance
                pq.pop();

                // Update distances to adjacent nodes
                for(const auto& it: adj[node]) {
                    auto [adjNode, edgeWt] = it;

                    if(dist[adjNode] > wt + edgeWt) {
                        dist[adjNode] = wt + edgeWt;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }

            // Count cities within the distance threshold
            int count = 0;
            for(int d: dist)
                if(d <= distanceThreshold) ++count;
            
            // Update the answer if the current city has fewer or equal reachable cities
            if(count <= min_count) {
                min_count = count;
                ans_city = i;
            }
        }

        return ans_city;
    }
};