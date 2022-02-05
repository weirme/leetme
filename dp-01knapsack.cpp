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

int knapsack(vector<int> values, vector<int> weights, int n, int w) {
    vector<vector<int>> dp(n+1, *new vector<int>(w+1, 0));
    for (int i = 1; i <= n; i++) {
        int vi = values[i-1], wi = weights[i-1];
        for (int j = 1; j <= w; j++) {
            if (wi <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-wi] + vi);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}
