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
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, {1, 1});
        int res = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1]+1);
                else if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0]+1);
            }
            res = max({res, dp[i][0], dp[i][1]});
        }
        return res;
    }
};
