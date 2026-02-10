#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b) {
            string order1 = a + b;
            string order2 = b + a;
            return order1 > order2; // Sort in descending order
        });

        if (strNums[0] == "0") {
            return "0";
        }

        string largestNumber = "";
        for (const string& num : strNums) {
            largestNumber += num;
        }

        return largestNumber;
    }
};
