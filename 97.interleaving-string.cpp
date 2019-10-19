#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const size_t M = s1.size(), N = s2.size();
        if (M + N != s3.size()) return false;
        bool dp[M+1][N+1];
        dp[0][0] = true;
        for (int i = 0; i < M; i++) dp[i+1][0] = dp[i][0] && s1[i] == s3[i];
        for (int j = 0; j < N; j++) dp[0][j+1] = dp[0][j] && s2[j] == s3[j];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                dp[i+1][j+1] = (dp[i][j+1] && s1[i] == s3[i+j+1]) || (dp[i+1][j] && s2[j] == s3[i+j+1]);
        return dp[M][N];
    }
};
