#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int start = 0;
        int maxlength = 0;
        unordered_set<char> seenChar;
        for(int i = 0; i < n; i++){
            while(seenChar.count(s[i])){
                seenChar.erase(s[start]);
                start++;
            }
            seenChar.insert(s[i]);
            maxlength = max(maxlength, i - start + 1);
        }
        return maxlength;
    }
};
