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
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), {0, nums[0]});
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+nums[i];
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};
