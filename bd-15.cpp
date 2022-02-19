#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i > 0 && nums[i-1] == nums[i]) continue;
            int l = i+1, r = nums.size()-1;
            int x = -nums[i];
            while (l < r) {
                if (l > i+1 && nums[l-1] == nums[l]) l++;
                else if (r < nums.size()-1 && nums[r] == nums[r+1]) r--;
                else {
                    if (nums[l] + nums[r] == x) {
                        res.push_back({nums[i], nums[l], nums[r]});
                        l++;
                        r--;
                    }
                    else if (nums[l] + nums[r] < x) l++;
                    else r--;
                }
            }
        }
        return res;
    }
};
