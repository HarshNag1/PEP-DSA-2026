#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Edge case: if s1 is longer than s2, s2 cannot contain s1's permutation
        if (s1.length() > s2.length()) {
            return false;
        }

        // Array to store character frequency for s1 and for the current window in s2
        vector<int> s1Freq(26, 0);
        vector<int> windowFreq(26, 0);

        // Fill the frequency array for s1
        for (int i = 0; i < s1.length(); i++) {
            s1Freq[s1[i] - 'a']++;
            windowFreq[s2[i] - 'a']++;
        }

        // Check the first window
        if (matches(s1Freq, windowFreq)) {
            return true;
        }

        // Slide the window over s2
        for (int i = s1.length(); i < s2.length(); i++) {
            // Add new character to the window
            windowFreq[s2[i] - 'a']++;
            // Remove the old character from the window
            windowFreq[s2[i - s1.length()] - 'a']--;

            // Check if the new window matches the frequency map of s1
            if (matches(s1Freq, windowFreq)) {
                return true;
            }
        }

        return false;
    }

private:
    // Helper function to check if two frequency arrays match
    bool matches(const vector<int>& s1Freq, const vector<int>& windowFreq) {
        for (int i = 0; i < 26; i++) {
            if (s1Freq[i] != windowFreq[i]) {
                return false;
            }
        }
        return true;
    }
};
