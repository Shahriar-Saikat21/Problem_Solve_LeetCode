#include<bits/stdc++.h>

using namespace std;

/*
You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. 
The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a
value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values 
is maximized.Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them 
starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next 
event must start at or after t + 1.

Example 1:

Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

Example 2:

Example 1 Diagram
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.

Example 3:

Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.

*/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int maxVal = 0, ans = 0;

        for (const auto& event : events) {
            int start = event[0], end = event[1], value = event[2];

            while (!pq.empty() && pq.top().first < start) {
                maxVal = max(maxVal, pq.top().second);
                pq.pop();
            }

            ans = max(ans, maxVal + value);
            pq.push({end, value});
        }

        return ans;
    }
};