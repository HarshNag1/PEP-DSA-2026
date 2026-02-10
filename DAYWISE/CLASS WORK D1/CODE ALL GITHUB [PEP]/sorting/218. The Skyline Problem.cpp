#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        vector<pair<int, int>> event;
        for (const auto& b : buildings) {
            event.push_back({b[0], -b[2]}); 
            event.push_back({b[1], b[2]}); 
        }
        sort(event.begin(), event.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if(a.first != b.first){
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        
        multiset<int> ms;
        ms.insert(0);
        int prev = 0;

        for(const auto& e : event){
            int x = e.first;
            int h = e.second;
            if(h < 0){
                ms.insert(-h);
            }
            else{
                auto it = ms.find(h);
                if(it != ms.end()) {
                    ms.erase(it);
                }
            }

            int curr = *ms.rbegin();
            if(curr != prev){
                result.push_back({x, curr});
                prev = curr;
            }
        }
        return result;
    }
};
