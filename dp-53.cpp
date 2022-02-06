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
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], 0) + nums[i];
            res = max(dp[i], res);
        }
        return res;
    }
};
