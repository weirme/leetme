#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        const int M = word1.size()+1, N = word2.size()+1;
        int dp[M][N];
        for (int i = 0; i < M; i++) dp[i][0] = i;
        for (int j = 0; j < N; j++) dp[0][j] = j;
        for (int i = 1; i < M; i++) {
            for (int j = 1; j < N; j++) {
                if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
        return dp[M-1][N-1];
    }
};
