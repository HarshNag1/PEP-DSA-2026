#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0]; // Sort width in increasing order
            return a[1] > b[1]; // Sort height in decreasing order
        });
        
        vector<int> dp(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            // lower_bound finds the first element >= value
            int lo = 0, hi = ans;
            while(lo < hi){
                int m = lo + (hi - lo) / 2;
                if(dp[m] < envelopes[i][1]){
                    lo = m + 1;
                } else {
                    hi = m;
                }
            }
            
            dp[lo] = envelopes[i][1];
            if(lo == ans) ans++;
        }
        return ans;
    }
};
