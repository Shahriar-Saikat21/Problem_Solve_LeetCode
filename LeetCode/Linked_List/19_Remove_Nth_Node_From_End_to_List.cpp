#include<bits/stdc++.h>

using namespace std;

/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n <= 0) {
            return head;
        }

        int size = 0;

        ListNode* temp = head;

        while(temp != NULL){
            size++;
            temp = temp->next;
        }

        int remove = size-n;

        temp = head;
        ListNode* prev = NULL;
        int a = 0;

        while (temp != NULL) {
            if (a == remove) {
                if (prev != NULL) {
                    prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                delete temp;
                return head;
            }
            prev = temp;
            temp = temp->next;
            a++;
        }
        return head;

    }
};