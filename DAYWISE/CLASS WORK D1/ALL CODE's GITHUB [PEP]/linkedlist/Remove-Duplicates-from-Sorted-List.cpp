#include <iostream>

using namespace std;

// 83. Remove Duplicates from Sorted List

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while(temp != nullptr && temp->next != nullptr){
            ListNode* nextNode = temp->next;
            while(nextNode != nullptr && nextNode->val == temp->val){
                nextNode = nextNode->next;
            }
            temp->next = nextNode;
            temp = temp->next;
        }
        return head;    
    }
};
