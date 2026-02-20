#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr(m, 0);
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
          for(int j = 0; j < m; j++){
              if(i == 0){
                  arr[j] = matrix[i][j] - '0';
              } else {
                  if(matrix[i][j] == '1'){
                      arr[j] += matrix[i][j] - '0';
                  } else {
                      arr[j] = 0;
                  } 
              }
              
          }
          maxi = max(maxi, largestRectangleArea(arr));
      }
        
      return maxi;  
        
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int ans = 0;
        for(int i = 0; i <= heights.size(); i++){
            int temp = 0;
            if(i != heights.size()) temp = heights[i];
            while(s.size() > 0 && temp < heights[s.top()]){
                int tbs = s.top();
                s.pop();
                int nsr = i;
                int x1 = nsr - 1;
                int nsl = -1;
                if(s.size() != 0) nsl = s.top();
                int x2 = nsl + 1;
                int area = heights[tbs] * (x1 - x2 + 1);
                ans = max(ans, area);
            }
            s.push(i);
        }
        return ans;
    }
};
