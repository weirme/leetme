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
    int numSquares(int n) {
        vector<int> dp(n+1, 1e4);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int sq = sqrt(i);
            if (sq*sq == i) {
                dp[i] = 1;
                continue;
            }
            for (int j = 0; j <= sq; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+dp[j*j]);
            }
        }
        return dp[n];
    }
};
