#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());      
        int n = nums.size();
        int count = 0;

        // Step 2: Fix the largest side
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // If nums[i] + nums[j] > nums[k],
                    // then all elements between i and j form valid pairs with nums[j]
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};
