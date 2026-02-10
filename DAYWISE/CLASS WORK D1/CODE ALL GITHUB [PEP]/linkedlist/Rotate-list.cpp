#include <iostream>

using namespace std;

// 61. Rotate List

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }
        int count = 1;
        ListNode* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
            count++;
        }
        temp->next = head;
        k = k % count;
        int stepToNewHead = count - k;
        ListNode* newTail = temp;
        while(stepToNewHead-- > 0){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};
