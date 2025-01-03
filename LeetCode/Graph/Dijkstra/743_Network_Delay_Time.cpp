#include<bits/stdc++.h>

using namespace std;

/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, 
a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, 
vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive 
the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //Adjacency list -> weight,target_vertex
        vector<pair<int,int>> adj[n+1];
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        // distance,vertex
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n+1, INT_MAX);

        dist[k] = 0;
        pq.push({0,k});

        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto x: adj[node]){
                int d = x.first;
                int nd = x.second;

                if(distance+d < dist[nd]){
                    dist[nd] = distance+d;
                    pq.push({distance+d , nd});
                }
            }
        }

        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }

        return ans;

    }
};

/*
Dijkstra formula: if d(u) + d(u,v) < d(v) then d(v) = d(u) + d(u,v)
Here just reverse the formula as the ques needs to find max probability
*/
