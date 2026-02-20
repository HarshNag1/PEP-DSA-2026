#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    bool canweplace(vector<int>& position, int dist, int cow){
        int n = position.size();
        int cnt = 1;
        int last = position[0];
        for(int i=1; i<n; i++){
            if(position[i] - last >= dist){
                cnt++;
                last = position[i];
            }
            if(cnt >= cow){
                return true;
            }
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1;
        int high = position[n-1] - position[0];
        int ans = 0; // Initialize ans
        while(low <= high){
            int mid = (low + high) / 2;
            if(canweplace(position, mid, m) == true){
                ans = mid; // Store valid answer (though high will converge to it effectively in this binary search pattern usually, but let's follow standard upper boundish check or just return high as in Java code)
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high; // The Java code returns high. For "maximize minimum", high is usually the answer after loop terminates if we use this valid range check.
    }
};
