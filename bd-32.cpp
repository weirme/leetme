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

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == ')' && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(')
                dp[i] = dp[max(0, i-dp[i-1]-2)] + dp[i-1] + 2;
            res = max(res, dp[i]);
        }
        return res;
    }
};
