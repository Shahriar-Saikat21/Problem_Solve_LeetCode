#include<bits/stdc++.h>

using namespace std;

/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before 
nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;

        // Traverse the list
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // End the list after the last greater node
        greater->next = nullptr;

        // Connect the last less node to the first greater node
        less->next = greaterDummy.next;

        // Return the first less node
        return lessDummy.next;
    }
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes for less and greater/equal lists
        ListNode* lessHead = new ListNode(0);
        ListNode* greaterHead = new ListNode(0);
        
        // Pointers to build the lists
        ListNode* less = lessHead;
        ListNode* greater = greaterHead;
        
        // Traverse the original list
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        greater->next = nullptr; 
        less->next = greaterHead->next;
        
        return lessHead->next;
    }
};