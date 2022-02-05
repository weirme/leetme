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
private:
    int quickSolve(vector<int>& prices) {
        vector<int> dp = {0, -prices[0]};
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = max(dp[0], dp[1]+prices[i]);
            dp[1] = max(dp[1], dp[0]-prices[i]);
        }
        return dp[0];
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        if (2*k >= prices.size()) {
            return quickSolve(prices);
        }
        vector<vector<int>> dp(k+1, {0, -prices[0]});
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= k; j++) {
                dp[j][0] = max(dp[j][0], dp[j][1]+prices[i]);
                dp[j][1] = max(dp[j][1], dp[j-1][0]-prices[i]);
            }
        }
        return dp[k][0];
    }
};
