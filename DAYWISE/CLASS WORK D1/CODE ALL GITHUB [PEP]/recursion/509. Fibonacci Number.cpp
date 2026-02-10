#include <iostream>

using namespace std;

// 509. Fibonacci Number

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        int temp = fib(n-1) + fib(n-2);
        return temp;
    }
};
