#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.length() > s.length()) {
            return ans;
        }
        
        unordered_map<char, int> hmp;
        unordered_map<char, int> hms;
        
        for (int i = 0; i < p.length(); i++) {
            char ch = p[i];
            hmp[ch]++;
        }
        
        for (int i = 0; i < p.length(); i++) {
            char ch = s[i];
            hms[ch]++;
        }
        
        if (hms == hmp) {
            ans.push_back(0);
        }
        
        int sp = 0;
        for (int ep = p.length(); ep < s.length(); ep++) {
            char c1 = s[ep];
            char c2 = s[sp];
            
            hms[c1]++;
            hms[c2]--;
            
            if (hms[c2] == 0) {
                hms.erase(c2);
            }
            
            sp++;
            
            if (hms == hmp) {
                ans.push_back(sp);
            }
        }
        
        return ans;
    }
};
