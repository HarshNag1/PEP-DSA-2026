#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);

        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string result = "";
        
        for (char c : s) {
            freq[c - 'a']--;

            if (visited[c - 'a']) continue;

            while (!result.empty() && 
                   result.back() > c && 
                   freq[result.back() - 'a'] > 0) {
                
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(c);
            visited[c - 'a'] = true;
        }

        return result;
    }
};
