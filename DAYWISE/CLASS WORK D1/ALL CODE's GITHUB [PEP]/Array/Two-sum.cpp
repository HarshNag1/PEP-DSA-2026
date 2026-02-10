#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<=n-2; i++){
            for(int j=i+1; j<=n-1; j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};
