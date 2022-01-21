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
    int translateNum(int num) {
        string str = to_string(num);
        int n = str.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        dp[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            dp[i] = dp[i+1];
            if (str[i] != '0' && (str[i] - '0') * 10 + str[i+1] - '0' < 26) {
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};
