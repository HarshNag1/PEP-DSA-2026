#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Priority queue (min-heap) to store elements from the lists
        // Stores {value, list index, element index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        int maxVal = INT_MIN; // Track the maximum value in the current range
        int start = 0, end = INT_MAX; // Track the smallest range

        // Initialize the heap with the first element from each list
        for (int i = 0; i < nums.size(); i++) {
            int element = nums[i][0];
            minHeap.push({element, i, 0});
            maxVal = max(maxVal, element); // Update the current max element
        }

        // Process the heap
        while (minHeap.size() == nums.size()) {
            vector<int> current = minHeap.top(); // Get the smallest element
            minHeap.pop();
            int value = current[0], listIndex = current[1], elementIndex = current[2];

            // Check if the current range [value, maxVal] is smaller than the previous range
            if (maxVal - value < end - start) {
                start = value;
                end = maxVal;
            }

            // If the current list has more elements, add the next element from the same list to the heap
            if (elementIndex + 1 < nums[listIndex].size()) {
                int nextValue = nums[listIndex][elementIndex + 1];
                minHeap.push({nextValue, listIndex, elementIndex + 1});
                maxVal = max(maxVal, nextValue); // Update the current max element
            }
        }

        return {start, end};
    }
};
