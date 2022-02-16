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
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(k+1, {0, -prices[0]});
        dp[0] = {0, 0};
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                dp[j][0] = max(dp[j][0], dp[j][1]+prices[i]);
                dp[j][1] = max(dp[j][1], dp[j-1][0]-prices[i]);
            }
        }
        return dp[k][0];
    }
};
