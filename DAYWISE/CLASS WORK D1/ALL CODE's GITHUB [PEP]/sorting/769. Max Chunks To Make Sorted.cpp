#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxVal = INT_MIN;
        int count = 0;
        for(int i = 0; i < n; i++){
            maxVal = max(maxVal, arr[i]);
            if(maxVal == i){
                count++;
            }
        }
        return count;
    }
};
