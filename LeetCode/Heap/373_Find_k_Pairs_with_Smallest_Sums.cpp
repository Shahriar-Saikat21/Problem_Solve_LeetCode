#include<bits/stdc++.h>

using namespace std;

/*
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
Define a pair (u, v) which consists of one element from the first array and one element from the second array.
Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: 
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: 
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> resV; // Result vector to store the pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // Priority queue to store pairs with smallest sums, sorted by the sum

        // Push the initial pairs into the priority queue
        for(int x : nums1) {
            pq.push({x + nums2[0], 0}); // The sum and the index of the second element in nums2
        }

        // Pop the k smallest pairs from the priority queue
        while(k-- && !pq.empty()) {
            int sum = pq.top().first; // Get the smallest sum
            int pos = pq.top().second; // Get the index of the second element in nums2

            resV.push_back({sum - nums2[pos], nums2[pos]}); // Add the pair to the result vector
            pq.pop(); // Remove the pair from the priority queue

            // If there are more elements in nums2, push the next pair into the priority queue
            if(pos + 1 < nums2.size()) {
                pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
            }
        }

        return resV; // Return the k smallest pairs
    }
};


/*
Intuition
It starts by inserting the pair sums of each element from nums1 and the first element of nums2 into a priority queue.
Since both arrays are sorted, the pair sums will be in increasing order.
By utilizing a priority queue, the smallest sum pair is always accessible at the top. 
The code then pops the smallest pair from the priority queue and adds it to the result vector. 
Next, it inserts the next pair, which consists of the same element from nums1 but the next element from nums2.
The code repeats this process, gradually inserting pairs with increasing elements from nums2, 
until it has added k pairs to the result vector or the priority queue becomes empty 
(i.e., all pairs have been explored). This ensures that only the k smallest pairs are considered.
Finally, the code returns the resulting vector containing the k smallest pairs.
Overall, the approach intelligently uses the priority queue to avoid unnecessary computations, 
allowing for an optimized solution with a time complexity of O(KlogN), where N represents the size of 
nums1 and K is the given parameter for the number of smallest pairs to find.
*/
