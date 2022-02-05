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
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, INF-1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (coins[i-1] <= j)
                    dp[j] = min(dp[j], dp[j-coins[i-1]]+1);
            }
        }
        if (dp[amount] == INF-1) return -1;
        return dp[amount];
    }
};
