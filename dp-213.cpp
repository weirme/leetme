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
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<vector<int>> dp(n, {0, 0});
        dp[1][0] = nums[1];
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-2][0]+nums[i]);
        }
        dp[0][1] = nums[0];
        dp[1][1] = max(nums[0], nums[1]);
        for (int i = 2; i < n-1; i++) {
            dp[i][1] = max(dp[i-1][1], dp[i-2][1]+nums[i]);
        }
        return max(dp[n-1][0], dp[n-2][1]);
    }
};
