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
    vector<double> dicesProbability(int n) {
        vector<vector<double>> dp(n+1, *new vector<double>(6*n+1, 0));
        for (int v = 1; v <= 6; v++) dp[1][v] = 1;
        for (int i = 2; i <= n; i++) {
            for (int k = i; k <= 6*i; k++) {
                dp[i][k] = 0;
                for (int v = 1; v <= min(6, k); v++) {
                    dp[i][k] += dp[i-1][k-v];
                }
            }
        }
        vector<double> res;
        double sum = pow(6, n);
        for (int k = n; k <= 6*n; k++) {
            res.push_back(dp[n][k]/sum);
        }
        return res;
    }
};
