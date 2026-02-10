#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 1545. Find Kth Bit in Nth Binary String

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }

        int len = (1 << n) - 1; 
        
        int mid = (len + 1) / 2;

        if (k < mid) {
            return findKthBit(n - 1, k);
        } else if (k == mid) {
            return '1';
        } else {
            int newK = len - k + 1; 
            return invert(findKthBit(n - 1, newK));
        }
    }

private:
    char invert(char c) {
        return (c == '0') ? '1' : '0';
    }
};
