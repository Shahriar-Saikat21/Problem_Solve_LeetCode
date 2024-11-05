#include<bits/stdc++.h>

using namespace std;

/*
You are given the head of a linked list containing unique integer values and an integer array nums that is a subset 
of the linked list values.Return the number of connected components in nums where two values are connected 
if they appear consecutively in the linked list.

Example 1:

Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.

Example 2:

Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,bool>mp;
        ListNode* temp = head;
        int result = 0, count = 0;

        for(int x: nums){
            mp[x] = true;
        }

        while(temp){
            if(mp[temp->val] == true){
                count++;
            }else{
                if(count !=0){
                    result++;
                    count = 0;
                }   
            }
            temp = temp->next;
        }
        if(count>0) result++;
         
        return result;
    }
};