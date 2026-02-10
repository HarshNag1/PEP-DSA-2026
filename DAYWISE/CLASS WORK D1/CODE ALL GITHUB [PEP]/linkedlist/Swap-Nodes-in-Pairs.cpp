#include <iostream>

using namespace std;

// 24. Swap Nodes in Pairs

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;

        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};
