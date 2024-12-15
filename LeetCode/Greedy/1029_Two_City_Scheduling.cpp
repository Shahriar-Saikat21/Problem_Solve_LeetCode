#include<bits/stdc++.h>

using namespace std;

/*
A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], 
the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

Example 1:

Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.
The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

Example 2:

Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859

Example 3:

Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output: 3086

*/
//Here Find the profit if i assign person at A how much i profit compared to B and take n/2 max profit index
//SORTING
class Solution {
    static bool comparator(vector<int>& a,vector<int>& b)
    {
        return a[1]-a[0] > b[1]-b[0];
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        sort(costs.begin(),costs.end(),comparator);
        int ans = 0;
        for(int i=0;i<n;++i)
            ans += i>=n/2?costs[i][1]:costs[i][0];
        
        return ans;
    }
};

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int res = 0;
        priority_queue<pair<int, int>> pq;
        
        for(int i=0; i<costs.size(); i++)
            pq.push(make_pair(costs[i][0] - costs[i][1], i));
        
        int halfSize = pq.size()/2;
        for(int i=0; i<halfSize; i++)
        {
            res += costs[pq.top().second][1];
            pq.pop();
        }
        
        for(int i=0; i<halfSize; i++)
        {
            res += costs[pq.top().second][0];
            pq.pop();
        }
        
        return res;
    }
};