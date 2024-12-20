#include<bits/stdc++.h>

using namespace std;

/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without 
modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [1]
Output: [1]

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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next ==NULL) return head;

        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* tail = dummy;
        ListNode* curr = head;

        while(curr && curr->next){
            ListNode* temp = curr->next->next;

            tail->next = curr->next;
            curr->next->next = curr;
            curr->next = temp;

            tail = curr;
            curr = temp;
        }

        return dummy->next;
    }
};