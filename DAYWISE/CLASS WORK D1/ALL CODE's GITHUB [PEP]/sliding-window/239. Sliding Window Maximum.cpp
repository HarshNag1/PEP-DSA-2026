#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        
        for(int i = 0; i <= n - k; i++){
            int maxVal = nums[i];
            for(int j = i; j < i + k; j++){
                maxVal = max(maxVal, nums[j]);
            }
            ans[i] = maxVal;
        }
        return ans;
    }
};
