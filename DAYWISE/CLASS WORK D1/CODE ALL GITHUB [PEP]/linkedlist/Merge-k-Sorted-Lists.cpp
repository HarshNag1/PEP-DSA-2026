#include <vector>
#include <queue>
#include <iostream>

using namespace std;

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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        // Min-heap to store nodes by value
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

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
