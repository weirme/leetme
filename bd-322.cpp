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

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int c : coins) {
            for (int i = 1; i <= amount; i++) {
                if (c <= i) dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};
