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
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    bool valid(char a, char b) {
        if (a == '0') return false;
        int val = (a-'0') * 10 + b-'0';
        return 1 <= val && val <= 26;
    }
    
public:
    int numDecodings(string s) {
        vector<int> dp(s.size());
        dp[0] = (s[0] != '0');
        if (s.size() == 1)
            return dp[0];
        dp[1] = (s[1] != '0') * dp[0] + valid(s[0], s[1]);
        for (int i = 2; i < s.size(); i++) {
            dp[i] = (s[i] != '0') * dp[i-1] + valid(s[i-1], s[i]) * dp[i-2];
        }
        return dp[s.size()-1];
    }
};
