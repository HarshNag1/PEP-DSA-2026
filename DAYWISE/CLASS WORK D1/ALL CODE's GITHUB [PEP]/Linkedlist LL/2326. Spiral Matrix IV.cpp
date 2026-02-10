#include <vector>
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
public:
    vector<vector<int>> spiralMatrix(int rows, int columns, ListNode* head) {
        vector<vector<int>> matrix(rows, vector<int>(columns, -1));

        int topRow = 0, bottomRow = rows - 1, leftColumn = 0, rightColumn = columns - 1;
        while (head != nullptr) {
        
            for (int col = leftColumn; col <= rightColumn && head != nullptr; col++) {
                matrix[topRow][col] = head->val;
                head = head->next;
            }
            topRow++;
            
            for (int row = topRow; row <= bottomRow && head != nullptr; row++) {
                matrix[row][rightColumn] = head->val;
                head = head->next;
            }
            rightColumn--;
            
            for (int col = rightColumn; col >= leftColumn && head != nullptr; col--) {
                matrix[bottomRow][col] = head->val;
                head = head->next;
            }
            bottomRow--;
            
            for (int row = bottomRow; row >= topRow && head != nullptr; row--) {
                matrix[row][leftColumn] = head->val;
                head = head->next;
            }
            leftColumn++;
        }

        return matrix;
    }
};
