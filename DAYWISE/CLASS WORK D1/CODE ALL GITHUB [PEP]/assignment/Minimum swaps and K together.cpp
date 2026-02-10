#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        int totalks = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= k){
                totalks++;
            }
        }
        if(totalks == 0 || totalks == n){
            return 0;
        }
        int currKs = 0;
        for(int i=0; i<totalks; i++){
            if(arr[i] <= k){
                currKs++;
            }
        }
        int maxks = currKs;
        for(int i=totalks; i<n; i++){
            if(arr[i - totalks] <= k){
                currKs--;
            }
            if(arr[i] <= k){
                currKs++;
            }
            maxks = max(maxks, currKs);
        }
        return totalks - maxks;
    }
};
