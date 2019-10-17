#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp;
        dp.push_back(1);
        dp.push_back(1);
        int temp;
        for (int i = 2; i <= n; i++) {
            temp = 0;
            for (int j = 0; j < i; j++)
                temp += dp[j] * dp[i-j-1];
            dp.push_back(temp);
        }
        return dp[n];
    }
};
