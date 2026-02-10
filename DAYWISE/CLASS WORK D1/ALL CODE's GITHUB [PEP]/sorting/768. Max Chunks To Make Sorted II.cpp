#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixmax(n);
        prefixmax[0] = arr[0];
        for(int i = 1; i < n; i++){
            prefixmax[i] = max(prefixmax[i - 1], arr[i]);
        }
        
        vector<int> suffixmax(n); // Variable name kept as per original logic, though it stores min
        suffixmax[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            suffixmax[i] = min(suffixmax[i + 1], arr[i]);
        }
        int count = 0;
        for(int i = 0; i < n - 1; i++){
            if(prefixmax[i] <= suffixmax[i + 1]){
                count++;
            }
        }
        count++;
        return count;
    }
};
