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
private:
    const pair<int, int> func(string& s) {
        int n = 0;
        for (auto& c : s) n += c-'0';
        return {s.size()-n, n};
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<vector<int>>> dp(len+1, *new vector<vector<int>>(m+1, *new vector<int>(n+1, 0)));
        for (int i = 1; i <= len; i++) {
            auto& [z, o] = func(strs[i-1]);
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (z <= j && o <= k)
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-z][k-o]+1);
                    else
                        dp[i][j][k] = dp[i-1][j][k];
                }
            }
        }
        return dp[len][m][n];
    }
};
