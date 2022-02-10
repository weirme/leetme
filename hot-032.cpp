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
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '(') continue;
            if (s[i-1] == '(') {
                dp[i] = 2;
                if (i-2 >= 0) dp[i] += dp[i-2];
            }
            else if (i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                dp[i] = dp[i-1] + 2;
                if (i-dp[i-1]-1 > 0) dp[i] += dp[i-dp[i-1]-2];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
