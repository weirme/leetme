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
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> dp(n+2);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
        }
        for (int i = 4; i <= n; i++) {
            for (int j = 2; j <= i/2; j++) {
                dp[i] = max(dp[i], dp[j] * dp[i-j]);
            }
        }
        return dp[n];
    }
};
