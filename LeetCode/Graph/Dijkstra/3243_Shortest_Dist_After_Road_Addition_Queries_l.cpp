#include<bits/stdc++.h>

using namespace std;

/*
You are given an integer n and a 2D integer array queries.There are n cities numbered from 0 to n - 1. Initially, 
there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1. queries[i] = [ui, vi] represents 
the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of 
the shortest path from city 0 to city n - 1.
Return an array answer where for each i in the range [0, queries.length - 1], 
answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

Example 1:

Input: n = 5, queries = [[2,4],[0,2],[0,4]]
Output: [3,2,1]
Explanation:
After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.
After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.
After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.

Example 2:

Input: n = 4, queries = [[0,3],[0,2]]
Output: [1,1]
Explanation:
After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.
After the addition of the road from 0 to 2, the length of the shortest path remains 1.

*/

class Solution {
public:
    int dijkstra(int start, int end, int n, const vector<vector<int>>& graph){
        vector<int>distance(n,INT_MAX);
        queue<int>q;

        distance[start]=0;
        q.push(start);

        while(!q.empty()){
            int current = q.front();
            q.pop();

            for(auto i: graph[current]){
                if(distance[i] > distance[current]+1){
                    distance[i] = distance[current]+1;
                    q.push(i);
                }
            }
        }

        return distance[end];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>answer;
        // Make Graph
        vector<vector<int>>graph(n);
        for(int i=0; i<n-1; i++){
            graph[i].push_back(i+1);
        }

        for(auto q: queries){
            graph[q[0]].push_back(q[1]);
            answer.push_back(dijkstra(0,n-1,n,graph));
        }

        return answer;
    }
};

