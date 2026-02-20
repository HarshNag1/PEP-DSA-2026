#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int value;
        int row;
        int col;

        Node(int value, int row, int col) {
            this->value = value;
            this->row = row;
            this->col = col;
        }
    };

    struct compare {
        bool operator()(const Node& a, const Node& b) {
            return a.value > b.value;
        }
    };

public:
    vector<int> solve(vector<vector<int>>& A) {
        if(A.empty() || A[0].empty()) return {};
        int K = A.size();
        int N = A[0].size();

        priority_queue<Node, vector<Node>, compare> minHeap;

        for (int i = 0; i < K; i++) {
            minHeap.push(Node(A[i][0], i, 0));
        }

        vector<int> result;
        result.reserve(K * N);

        while (!minHeap.empty()) {
            Node curr = minHeap.top();
            minHeap.pop();
            result.push_back(curr.value);

            if (curr.col + 1 < N) {
                minHeap.push(Node(
                    A[curr.row][curr.col + 1],
                    curr.row,
                    curr.col + 1
                ));
            }
        }

        return result;
    }
};
