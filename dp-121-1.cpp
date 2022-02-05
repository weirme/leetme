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
        int dp0 = 0, dp1 = -INF;
        for (int i = 0; i < prices.size(); i++) {
            dp0 = max(dp0, dp1+prices[i]);
            dp1 = max(dp1, -prices[i]);
        }
        return dp0;
    }
};
