#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return 0;
        }

        sort(nums.begin(), nums.end());
        int maxGap = 0;
        for(int i = 1; i < n; i++){
            maxGap = max(maxGap, (nums[i] - nums[i - 1]));
        }
        return maxGap;
    }
};
