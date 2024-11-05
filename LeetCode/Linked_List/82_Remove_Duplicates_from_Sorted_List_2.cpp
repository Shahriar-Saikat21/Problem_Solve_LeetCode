#include<bits/stdc++.h>

using namespace std;

/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]

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
    ListNode* deleteDuplicates(ListNode* head) {
        // Handle edge cases where the list is empty or has only one node
        if (head == NULL || head->next == NULL) {
            return head;  // No duplicates to remove, return the list as is
        }

        // Create a dummy node that points to the head of the list
        // This helps in handling cases where the first few nodes are duplicates
        ListNode* dummy = new ListNode(0, head);
        
        // Initialize 'prev' to point to the dummy node
        // 'prev' will be used to link nodes that are not part of any duplicate sequence
        ListNode* prev = dummy;
        
        // Initialize 'curr' to start at the head of the list
        // 'curr' will be used to traverse through the list
        ListNode* curr = head;

        // Traverse through the list until the end
        while (curr != NULL) {
            // Check if the current node has a duplicate
            if (curr->next != NULL && curr->val == curr->next->val) {
                // Skip all nodes that have the same value as 'curr'
                // Move 'curr' forward until the last duplicate node
                while (curr->next != NULL && curr->val == curr->next->val) {
                    curr = curr->next;
                }
                // Link 'prev->next' to the node after the last duplicate
                // This effectively removes the sequence of duplicates
                prev->next = curr->next;
            } else {
                // If no duplicate is found, move 'prev' to the current node
                prev = curr;
            }
            // Move 'curr' to the next node in the list
            curr = curr->next;
        }

        // Return the modified list, starting from 'dummy->next'
        // We skip the dummy node itself
        return dummy->next;
    }
};