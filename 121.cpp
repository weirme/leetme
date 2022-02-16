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
    int maxProfit(vector<int>& prices) {
        vector<int> dp = {0, -prices[0]};
        for (int i = 1; i < prices.size(); i++) {
            dp[0] = max(dp[0], dp[1]+prices[i]);
            dp[1] = max(dp[1], -prices[i]);
        }
        return dp[0];
    }
};
