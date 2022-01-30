#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                res[0] = i;
                res[1] = it->second;
                break;
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return res;
    }
};
