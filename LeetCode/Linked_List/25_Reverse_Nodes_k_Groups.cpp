#include<bits/stdc++.h>

using namespace std;

/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes 
is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;
        int n = 0; // count
        ListNode *curr = head;
        while(curr){
            n++;
            curr = curr->next;
        }
        
        ListNode *prev = nullptr, *next, *newHead; 
        ListNode *t1 = nullptr, *t2 = head;
        curr = head;
        
        while(n >= k){
            //Reverse k List
            for(int i = 0; i < k; i++){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            if(!newHead) newHead = prev;

            if(t1) t1->next = prev;
            t2->next = curr; // n is not multiple of k
            t1 = t2;
            t2 = curr;
            
            prev = nullptr;
            n -= k;
        }
        return newHead;
    }
};