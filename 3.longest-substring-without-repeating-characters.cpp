#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int N = s.size();
        if (N == 0) return 0;
        int dp[N] = {1};
        int res = 1;
        for (int i = 1; i < N; i++) {
            int j = i-1;
            while (j >= i - dp[i-1] && s[i] != s[j]) j--;
            if (j >= i - dp[i-1]) dp[i] = i - j;
            else dp[i] = dp[i-1] + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};