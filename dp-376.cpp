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
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        vector<vector<int>> dp(n, {1, 1});
        for (int i = 1; i < n; i++) {
            if (nums[i-1] < nums[i]) {
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = dp[i-1][1];
            }
            else if (nums[i-1] > nums[i]) {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][0] + 1;
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

int main() {
    vector<int> nums = {0, 0};
    Solution s;
    s.wiggleMaxLength(nums);
    return 0;
}
