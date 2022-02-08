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

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, *new vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            res++;
        }
        for (int i = 0; i < n-1; i++) {
            if ((dp[i][i+1] = (s[i] == s[i+1]))) res++;
        }
        for (int k = 2; k < n; k++) {
            for (int i = 0; i < n-k; i++) {
                if ((dp[i][i+k] = dp[i+1][i+k-1] && s[i] == s[i+k])) res++;
            }
        }
        return res;
    }
};

int main() {
    string str = "abcaac";
    Solution s;
    int res = s.countSubstrings(str);
    return 0;
}
