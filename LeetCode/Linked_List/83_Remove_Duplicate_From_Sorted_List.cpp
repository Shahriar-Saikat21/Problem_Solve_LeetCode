#include<bits/stdc++.h>

using namespace std;
/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==NULL|| head->next==NULL) return head;

        unordered_set<int> s;

        ListNode* start = head;
        ListNode* prev = NULL;

        while(start != NULL){
            if(s.find(start->val)!=s.end()){
                prev->next=start->next;
            }else{
                s.insert(start->val);
                prev=start;
            }
            start=start->next;
        }
        return head;
    }
};

class Solution2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode* curr = head;
        while(curr!=NULL and curr->next!=NULL){
            if(curr->val==curr->next->val){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            }
            else curr=curr->next;
        }
        return head;
    }
};