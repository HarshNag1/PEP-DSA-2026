#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // convert input to minutes
        int n = timePoints.size();
        vector<int> minutes(n);
        for (int i = 0; i < n; i++) {
            string time = timePoints[i];
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3));
            minutes[i] = h * 60 + m;
        }

        // sort times in ascending order
        sort(minutes.begin(), minutes.end());

        // find minimum difference across adjacent elements
        int ans = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, minutes[i + 1] - minutes[i]);
        }

        // consider difference between last and first element
        return min(ans, 24 * 60 - minutes[n - 1] + minutes[0]);
    }
};
