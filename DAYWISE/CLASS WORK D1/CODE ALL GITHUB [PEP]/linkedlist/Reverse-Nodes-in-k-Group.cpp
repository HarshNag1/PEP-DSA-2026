#include <iostream>

using namespace std;
// 25. Reverse Nodes in k-Group

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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    
    ListNode* getKthNode(ListNode* temp, int k){
        k -= 1;
        while(temp != nullptr && k > 0){
            k = k - 1;
            temp = temp->next;
        }
        return temp;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* KthNode = getKthNode(temp, k);
            if(KthNode == nullptr){
                if(prev != nullptr){
                    prev->next = temp;
                }
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = nullptr;
            reverseLinkedList(temp);

            if(temp == head){
                head = KthNode;
            }
            else{
                prev->next = KthNode;
            }
            prev = temp;
            temp = nextNode;
        }
        return head;
    }
};
