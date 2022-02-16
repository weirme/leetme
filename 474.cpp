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
private:
    pair<int, int> getpair(string s) {
        int n = s.size();
        int one = 0;
        for (char c : s) one += c-'0';
        return {n-one, one};
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, *new vector<int>(n+1, 0));
        vector<pair<int, int>> vec(strs.size());
        for (int i = 0; i < strs.size(); i++) vec[i] = getpair(strs[i]);
        for (auto [a, b] : vec) {
            for (int i = m; i >= a; i--) {
                for (int j = n; j >= b; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-a][j-b]+1);
                }
            }
        }
        return dp[m][n];
    }
};
