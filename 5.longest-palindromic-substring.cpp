#include <iostream>
#include <string>

using namespace std;
const int N = 1010;

class Solution {
public:
    string longestPalindrome(string s) {
        int dp[N][N];
        int n = s.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int i = 0; i < n-1; i++) dp[i][i+1] = (s[i] == s[i+1]);
        for (int t = 2; t < n; t++) {
            for (int i = 0; i < n-t; i++) {
                dp[i][i+t] = dp[i+1][i+t-1] && (s[i] == s[i+t]);
            }
        }
        pair<int, int> res(0, 0);
        for (int i = 0; i < n; i++) 
            for (int j = i; j < n; j++) 
                if (dp[i][j] && (res.second < j-i+1)) res = make_pair(i, j-i+1);  
        return s.substr(res.first, res.second);
    }
};