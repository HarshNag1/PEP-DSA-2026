#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int duplicate = -1;
        int missing = -1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                duplicate = nums[i];
            }
            else if(nums[i] - nums[i - 1] > 1){
                missing = nums[i - 1] + 1;
            }
        }
        if(nums[0] != 1){
            missing = 1;
        }
        else if(nums[n - 1] != n){
            missing = n;
        }
        return {duplicate, missing};
    }
};
