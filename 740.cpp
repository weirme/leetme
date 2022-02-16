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
    int deleteAndEarn(vector<int>& nums) {
        int m = 0;
        for (int n : nums) m = max(n, m);
        vector<int> cnt(m+1, 0);
        for (int n : nums) cnt[n]++;
        vector<vector<int>> dp(m+1, {0, 0});
        for (int i = 1; i <= m; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + cnt[i]*i;
        }
        return max(dp[m][0], dp[m][1]);
    }
};
