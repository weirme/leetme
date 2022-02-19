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
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, *new vector<bool>(n, false));
        int begin = 0, len = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 1; i < n; i++) {
            if (s[i-1] == s[i]) {
                dp[i-1][i] = true;
                begin = i-1;
                len = 2;
            }
        }
        for (int k = 2; k < n; k++) {
            for (int i = k; i < n; i++) {
                dp[i-k][i] = dp[i-k+1][i-1] && (s[i-k] == s[i]);
                if (dp[i-k][i]) {
                    begin = i-k;
                    len = k+1;
                }
            }
        }
        return s.substr(begin, len);
    }
};
