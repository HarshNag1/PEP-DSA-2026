#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> result;
        for(int num : nums1){
            map[num]++;
        }

        for(int num : nums2){
            if(map.count(num) && map[num] > 0){
                result.push_back(num);
                map[num]--;
            }
        }

        return result;
    }
};
