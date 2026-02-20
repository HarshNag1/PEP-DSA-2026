#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, 0);
        stack<int> s;
        
        for (int i = n - 1; i >= 0; i--) {
            
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            
            result[i] = s.empty() ? -1 : s.top();
            
            s.push(arr[i]);
        }
        
        return result;
    }
};
