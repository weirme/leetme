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
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> travel(366, false);
        for (int d : days) travel[d] = true;
        vector<int> dp(366, 0);
        for (int i = 1; i <= 365; i++) {
            if (travel[i]) {
                dp[i] = min({
                    dp[i-1]+costs[0],
                    dp[max(0, i-7)]+costs[1],
                    dp[max(0, i-30)]+costs[2]
                });
            }
            else dp[i] = dp[i-1];
        }
        return dp[365];
    }
};
