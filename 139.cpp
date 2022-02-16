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
    bool cmp(string& s, int pos, string& p) {
        int i = pos, j = p.size()-1;
        while (i >= 0 && j >= 0 && s[i] == p[j]) {
            i--;
            j--;
        }
        return j < 0;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (auto word : wordDict) {
                dp[i] = dp[i] || (cmp(s, i-1, word) && dp[i-word.size()]);
            }
        }
        return dp[n];
    }
};
