#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[maxIndex]){
                maxIndex = i;
            }
        }
        for(int i = 0; i < n; i++){
            if(i != maxIndex && nums[maxIndex] < 2LL * nums[i]){ // Use long long to prevent overflow although inputs are int
               return -1;
            }
        }
        return maxIndex;
    }
};
