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
#include <unordered_set>
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i+1, r = nums.size()-1;
            int v = -nums[i];
            while (l < r) {
                if (l > i+1 && nums[l-1] == nums[l]) {
                    l++;
                    continue;
                }
                if (r < nums.size()-1 && nums[r] == nums[r+1]) {
                    r--;
                    continue;
                }
                if (l >= r) break;
                if (nums[l] + nums[r] == v) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] < v) l++;
                else r--;
            }
        }
        return res;
    }
};
