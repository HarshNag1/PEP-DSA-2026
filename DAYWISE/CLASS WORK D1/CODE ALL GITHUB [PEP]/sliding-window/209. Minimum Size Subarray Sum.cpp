#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        int minLength = INT_MAX;

        for(int i = 0; i < n; i++){
            int toFind = target + prefix[i];
            int bound = binarySearch(prefix, toFind);
            if(bound != -1){
                minLength = min(minLength, bound - i);
            }
        }
        return (minLength == INT_MAX) ? 0 : minLength;
    }

    int binarySearch(vector<int>& prefix, int target){
        int n = prefix.size();
        int left = 0;
        int right = n - 1;
        int ans = -1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(prefix[mid] >= target){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};
