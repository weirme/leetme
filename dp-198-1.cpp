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

const int INF = 0x7fffffff;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<vector<int>> dp(nums.size(), {0, 0});
        dp[0] = {0, nums[0]};
        dp[1] = {nums[0], max(nums[0], nums[1])};
        for (int i = 2; i < nums.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(dp[i-1][0], dp[i-2][1]) + nums[i];
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};
