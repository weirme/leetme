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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, *new vector<int>(n, 1e5));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) dp[i][j] = 0;
                else {
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (mat[i][j] == 0) dp[i][j] = 0;
                else {
                    if (i < m-1) dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
                    if (j < n-1) dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
                }
            }
        }
        return dp;
    }
};
