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
    int integerBreak(int n) {
        vector<int> dp(n+10);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        if (n <= 3) return dp[n];
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j <= i/2; j++) {
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
            }
        }
        return dp[n];
    }
};
