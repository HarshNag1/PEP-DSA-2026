#include <iostream>

using namespace std;

// 206. Reverse Linked List - Duplicate? But filename was different case in PEP
// Translating anyway.

/**
 * Definition for singly-linked list.
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }

        if(head->next == nullptr){
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(curr != nullptr){
            ListNode* currp1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currp1;
        }
        return prev;
    }
};
