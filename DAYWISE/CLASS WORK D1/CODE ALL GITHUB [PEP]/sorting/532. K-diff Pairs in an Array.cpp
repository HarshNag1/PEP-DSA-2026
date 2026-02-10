#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        int count = 0;
        while(i < n && j < n){
            if(i == j || nums[j] - nums[i] < k){
                j++;
            }
            else if(nums[j] - nums[i] > k){
                i++;
            }
            else{
                count++;
                i++;
                j++;
                
                while(j < n && nums[j] == nums[j - 1]){
                    j++;
                }
            }
        }
        return count;
    }
};
