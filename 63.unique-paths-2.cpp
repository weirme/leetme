#include <vector>

using namespace std;

class Solution {
public:
    long long uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int M = obstacleGrid.size(), N = obstacleGrid[0].size();
        long long dp[M+1][N+1];
        for (int i = 0; i <= M; i++) dp[i][0] = 0;
        for (int j = 0; j <= N; j++) dp[0][j] = 0;
        dp[0][1] = 1;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (obstacleGrid[i-1][j-1] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[M][N];
    }
};
