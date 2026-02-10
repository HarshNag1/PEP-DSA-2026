#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int ans = INT_MIN;

        while(i < j){
            int w = (j - i) * min(height[i], height[j]);
            ans = max(ans, w);
            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};
