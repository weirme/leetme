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
    vector<double> dicesProbability(int n) {
        vector<double> res;
        vector<vector<int>> dp(2);
        dp[0] = *new vector<int>(6*n+1, 0);
        dp[1] = *new vector<int>(6*n+1, 0);
        for (int j = 1; j <= 6; j++) {
            dp[1][j] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= 6 * i; j++) {
                dp[i&1][j] = 0;
                for (int k = 1; k <= 6; k++) {
                    dp[i&1][j] += dp[(i+1)&1][j-k];
                }
            }
        }
        for (int j = n; j <= 6*n; j++) {
            res.push_back(dp[n&1][j]/pow(6, n));
        }
        return res;
    }
};


int main() {
    Solution s;
    s.dicesProbability(5);
    return 0;
}
