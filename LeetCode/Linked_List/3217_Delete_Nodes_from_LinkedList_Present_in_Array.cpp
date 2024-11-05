#include<bits/stdc++.h>

using namespace std;
/*
You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all 
nodes from the linked list that have a value that exists in nums.The input is generated such that there is at least one node in the linked 
list that has a value not present in nums.All elements in nums are unique.

Example 1:

Input: nums = [1,2,3], head = [1,2,3,4,5]
Output: [4,5]
Explanation: Remove the nodes with values 1, 2, and 3.

Example 2:

Input: nums = [1], head = [1,2,1,2,1,2]
Output: [2,2,2]
Explanation: Remove the nodes with value 1.

Example 3:

Input: nums = [5], head = [1,2,3,4]
Output: [1,2,3,4]
Explanation: No node has value 5.
 
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s(nums.begin(),nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr!=NULL){
            if(s.find(curr->val) != s.end()){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};