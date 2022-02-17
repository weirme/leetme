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
private:
    bool valid(char a, char b) {
        int v = (a-'0')*10 + b-'0';
        return 10 <= v && v <= 26;
    }
    
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] != '0';
        for (int i = 2; i <= n; i++) {
            if (s[i-1] == '0') dp[i] = valid(s[i-2], s[i-1]) * dp[i-2];
            else dp[i] = dp[i-1] + valid(s[i-2], s[i-1]) * dp[i-2];
        }
        return dp[n];
    }
};
