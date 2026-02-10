#include <string>
#include <unordered_map>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        int matchcount = 0;
        
        for(int i = 0; i < t.length(); i++){
            char ch = t[i];
            tmap[ch]++;
        }
        int anslen = INT_MAX;
        int anssp = 0, ansep = 0;
        int sp = 0;
        int ep = 0;
        while(ep < s.length()){
            if(matchcount == t.length()){
                //release
                char ch1 = s[sp];
                if(ep - sp < anslen){
                    anslen = ep - sp;
                    anssp = sp;
                    ansep = ep;
                }
                smap[ch1]--;
                if(smap[ch1] < tmap[ch1]){
                    matchcount--;
                }
                sp++;
            } else {
                //acquire
                char ch2 = s[ep];
                smap[ch2]++;
                if(smap[ch2] <= tmap[ch2]){
                    matchcount++;
                }
                
                ep++;
            }
        }
        
        while(matchcount == t.length()){
            char ch1 = s[sp];
                if(ep - sp < anslen){
                    anslen = ep - sp;
                    anssp = sp;
                    ansep = ep;
                }
                smap[ch1]--;
                if(smap[ch1] < tmap[ch1]){
                    matchcount--;
                }
                sp++;
        }
        
        if (anslen == INT_MAX) return "";
        return s.substr(anssp, anslen);
    }
};
