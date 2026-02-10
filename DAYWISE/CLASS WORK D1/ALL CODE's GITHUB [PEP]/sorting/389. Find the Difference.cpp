#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for(char ch : s){
            result ^= ch;
        }
        for(char ch : t){
            result ^= ch;
        }
        return result;
    }
};
