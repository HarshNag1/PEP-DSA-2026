#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int maxLength = 0;
        int zerocount = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] == 0){
                zerocount++;
            }
            while(zerocount > k){
               if(nums[left] == 0){
                zerocount--;
               }
               left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
