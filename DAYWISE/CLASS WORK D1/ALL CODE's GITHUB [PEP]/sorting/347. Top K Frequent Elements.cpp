#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int num : nums){
            map[num]++;
        }
        
        // Min heap based on frequency
        auto comp = [&map](int a, int b) {
            return map[a] > map[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> minHeap(comp);

        for(auto const& [num, count] : map){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};
