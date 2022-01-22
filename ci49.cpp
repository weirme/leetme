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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        int p = 0, q = 0, r = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(min(dp[p]*2, dp[q]*3), dp[r]*5);
            if (dp[i] == dp[p]*2) p++;
            if (dp[i] == dp[q]*3) q++;
            if (dp[i] == dp[r]*5) r++;
        }
        return dp[n-1];
    }
};
