#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length() - 1;
        int m = num2.length() - 1;
        int i = n;
        int j = m;
        int carry = 0;
        string sb = "";
        while(i >= 0 || j >= 0 || carry != 0){
            int sum = carry;
            if(i >= 0){
                sum += num1[i] - '0';
                i--;
            }
            if(j >= 0){
                sum += num2[j] - '0';
                j--;
            }
            sb += to_string(sum % 10);
            carry = sum / 10;
        }
        reverse(sb.begin(), sb.end());
        return sb;
    }
};
