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
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), {0, 0});
        dp[0] = {0, -prices[0]-fee};
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]-fee);
        }
        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};
