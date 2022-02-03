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
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), *new vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); i++) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for (int j = 1; j < grid[0].size(); j++) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};
