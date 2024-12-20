#include<bits/stdc++.h>

using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;

        while(l1){
            s1.push(l1->val);
            l1=l1->next;
        }

        while(l2){
            s2.push(l2->val);
            l2=l2->next;
        }

        int carry = 0;
        int totalSum = 0;
        ListNode *temp = NULL;

        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                totalSum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                totalSum += s2.top();
                s2.pop();
            }

            carry = totalSum / 10;
            ListNode* newHead = new ListNode(totalSum % 10);
            newHead -> next = temp;
            temp = newHead;
            totalSum = carry;
        }

        if (carry != 0) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = temp;
            temp = newHead;
        }

        return temp; 
    }
};