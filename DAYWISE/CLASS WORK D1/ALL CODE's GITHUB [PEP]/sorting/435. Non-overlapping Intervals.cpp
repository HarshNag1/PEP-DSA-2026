#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = intervals.size();
        int count = 0;
        int prevEnd = INT_MIN;

        for(const auto& interval : intervals){
             if(interval[0] >= prevEnd){
                count++;
                prevEnd = interval[1];
             }
        }
        return n - count;
    }
};
