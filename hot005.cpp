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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    string longestPalindrome(string s) {
        size_t n = s.size();
        vector<vector<bool>> dp(n);
        int low = 0, len = 1;
        for (int i = 0; i < n; i++) {
            dp[i] = *new vector<bool>(n, false);
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        for (int i = 0; i < n-1; i++) {
            if ((dp[i][i+1] = (s[i] == s[i+1]))) {
                low = i;
                len = 2;
            }
        }
        for (int k = 2; k < n; k++) {
            for (int i = 0; i < n-k; i++) {
                if ((dp[i][i+k] = (s[i] == s[i+k]) && dp[i+1][i+k-1])) {
                    low = i;
                    len = k+1;
                }
            }
        }
        return s.substr(low, len);
    }
};
