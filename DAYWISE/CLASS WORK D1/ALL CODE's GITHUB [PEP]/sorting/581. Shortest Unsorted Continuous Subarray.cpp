#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1]){
                minVal = min(minVal, nums[i]);
            }
        }
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] > nums[i + 1]){
                maxVal = max(maxVal, nums[i]);
            }
        }
        if (minVal == INT_MAX) return 0;
        
        int l = 0;
        while(l < n && nums[l] <= minVal){
            l++;
        }
        int r = n - 1;
        while(r >= 0 && nums[r] >= maxVal){
            r--;
        }
        return r - l + 1;
    }
};
