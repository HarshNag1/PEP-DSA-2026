#include <iostream>

using namespace std;

// 50. Pow(x, n)

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // use long long to handle overflow when n = Integer.MIN_VALUE
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return power(x, N);
    }
    double power(double x, long long n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        double temp = power(x, n / 2);

        if(n % 2 == 0){
            return temp * temp;
        }
        else{
            return temp * temp * x;
        }
    }
};
