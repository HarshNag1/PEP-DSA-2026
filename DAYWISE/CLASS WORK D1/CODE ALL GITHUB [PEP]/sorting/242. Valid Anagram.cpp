#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        int arr[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for (int x : arr) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};
