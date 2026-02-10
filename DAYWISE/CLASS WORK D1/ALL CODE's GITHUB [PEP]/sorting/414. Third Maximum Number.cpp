#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Use long long to avoid overflow issues during comparison if any, though not strictly needed for unique logic
        // But for direct port of Java strategy (sort desc, find 3rd unique)
        sort(nums.begin(), nums.end(), greater<int>());
        
        int distinctCount = 1;
        int prev = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != prev){
                distinctCount++;
                prev = nums[i];
            }
            if(distinctCount == 3){
                return nums[i];
            }
        }
        return nums[0];
    }
};
