#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <iostream>

using namespace std;

class Solution {
    unordered_map<int, int> map;
    int valid;

public:
    Solution(int n, vector<int>& blacklist) {
        for(int b : blacklist){
            map[b] = -1;
        }
        valid = n - blacklist.size();
        for(int b : blacklist){
            if(b < valid){
                while(map.count(n - 1)){
                    n--;
                }
                map[b] = n - 1;
                n--;
            }
        }
    }
    
    int pick() {
        int val = rand() % valid;
        if(map.count(val)){
            return map[val];
        } else {
            return val;
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
