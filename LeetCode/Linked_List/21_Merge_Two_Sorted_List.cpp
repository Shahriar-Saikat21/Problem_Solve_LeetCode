#include<bits/stdc++.h>

using namespace std;
/*
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first 
two lists.
Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
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
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode();
        ListNode* s1 = list1;
        ListNode* s2 = list2;
        ListNode* temp = result;

        if(s1==NULL && s2!=NULL)return s2;

        if(s1!=NULL && s2==NULL) return s1;

        while(s1!=NULL && s2!=NULL){
            if(s1->val <= s2->val){
                temp->next = s1;
                s1 = s1->next;
            }else{
                temp->next = s2;
                s2 = s2->next;
            }
            temp = temp->next;
        }
        if(s1!=NULL) temp->next = s1;
        if(s2!=NULL) temp->next = s2;
        return result->next;
    }
};