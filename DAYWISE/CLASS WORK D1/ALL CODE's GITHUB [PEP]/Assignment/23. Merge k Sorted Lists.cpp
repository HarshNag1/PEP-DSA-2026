#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        // Min-heap to store nodes by value
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Add head of each list to the heap
        for (ListNode* node : lists) {
            if (node != nullptr) pq.push(node);
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Extract min and add next node
        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();
            
            tail->next = minNode;
            tail = tail->next;

            if (minNode->next != nullptr) {
                pq.push(minNode->next);
            }
        }

        return dummy->next;
    }
};
