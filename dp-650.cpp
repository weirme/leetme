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
    int minSteps(int n) {
        vector<int> dp(n+1);
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = i;
            for (int j = 1; j * j <= n; j++) {
                if (i % j == 0)
                    dp[i] = min(dp[i], dp[j]+dp[i/j]);
            }
        }
        return dp[n];
    }
};
