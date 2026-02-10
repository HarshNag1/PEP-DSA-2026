#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subArray(nums, k) - subArray(nums, k - 1);
    }
    
private:
    int subArray(vector<int>& nums, int k){
        if(k < 0){
            return 0;
        }
        int l = 0, r = 0;
        int sum = 0, count = 0;
        while(r < nums.size()){
            sum += nums[r] % 2;
            while(l <= r && sum > k){
                sum -= nums[l] % 2;
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
};
