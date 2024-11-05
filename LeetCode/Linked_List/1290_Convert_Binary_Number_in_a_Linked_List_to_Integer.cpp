#include<bits/stdc++.h>

using namespace std;

/*
Given head which is a reference node to a singly-linked list.The value of each node in the linked list is 
either 0 or 1.The linked list holds the binary representation of a number.Return the decimal value of the 
number in the linked list.The most significant bit is at the head of the linked list.

Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:

Input: head = [0]
Output: 0

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
    int getDecimalValue(ListNode* head) {
        vector<int>t;
        int result = 0, track = 1;
        ListNode* temp = head;

        while(temp != NULL){
            t.push_back(temp->val);
            temp = temp->next;
        }

        for(int i = t.size()-1; i>=0; i--){
            if(t[i]==1){
                result += (t[i]*track);
            }
            track *= 2;
        }

        return result;
    }
};