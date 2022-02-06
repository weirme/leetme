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
#include <numeric>

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < target || (sum-target)&1) return 0;
        target = (sum - target) / 2;
        vector<vector<int>> dp(nums.size()+1, *new vector<int>(target+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= target; j++) {
                if (j < nums[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][target];
    }
};

int main() {
    vector<int> nums = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53};
    Solution s;
    s.findTargetSumWays(nums, 1000);
    return 0;
}
