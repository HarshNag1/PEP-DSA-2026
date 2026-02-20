#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int left = 0;
        int right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
           
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            int leftVal = mid - 1 >= 0 ? mat[maxRow][mid - 1] : -1;
            int rightVal = mid + 1 < n ? mat[maxRow][mid + 1] : -1;
            
            if (mat[maxRow][mid] > leftVal && mat[maxRow][mid] > rightVal) {
                return {maxRow, mid};
            } 
            else if (leftVal > mat[maxRow][mid]) {
                right = mid - 1;
            } 
            else {
                left = mid + 1;
            }
        }
        
        return {-1, -1}; 
    }
};
