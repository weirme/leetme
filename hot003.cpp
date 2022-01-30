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
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        vector<int> dp(s.size());
        vector<int> last(128, -1);
        int res = 1;
        dp[0] = 1;
        last[s[0]] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (last[s[i]] < i - dp[i-1]) {
                dp[i] = dp[i-1] + 1;
            }
            else {
                dp[i] = i - last[s[i]];
            }
            last[s[i]] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};
