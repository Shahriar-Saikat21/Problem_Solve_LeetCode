#include<bits/stdc++.h>

using namespace std;
/*
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

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
    void reorderList(ListNode* head) {
        vector<ListNode*>temp1;
        vector<ListNode*>temp2;

        ListNode* cur = head;

        while(cur != NULL){
            temp1.push_back(cur);
            cur = cur->next;
        }

        int i=0, j= temp1.size()-1;

        while(i<=j){
            if(i==j){
                temp2.push_back(temp1[i]);
                break;
            }
            temp2.push_back(temp1[i]);
            temp2.push_back(temp1[j]);

            i++;
            j--;
        }

        head->next = NULL;
        cur = head;

        for(int i=1; i<temp2.size(); i++){
            ListNode* t = new ListNode(temp2[i]->val);
            cur->next = t;
            cur = cur->next;
        }
    }
};