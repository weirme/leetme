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
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(3, *new vector<int>(2, 0));
        for (int k=1; k < 3; k++) {
            dp[k] = {0, -prices[0]};
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int k = 1; k < 3; k++) {
                dp[k][0] = max(dp[k][0], dp[k][1] + prices[i]);
                dp[k][1] = max(dp[k][1], dp[k-1][0] - prices[i]);
            }
        }
        return dp[2][0];
    }
};
