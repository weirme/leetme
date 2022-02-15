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
#include <unordered_set>
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int v : coins) {
            for (int j = 1; j <= amount; j++) {
                if (v <= j) dp[j] = min(dp[j], dp[j-v]+1);
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};
