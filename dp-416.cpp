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
    bool canPartition(vector<int>& nums) {
        unsigned sum = 0;
        for (auto& ni : nums) sum += ni;
        if (sum&1) return false;
        sum >>= 1;
        int n = nums.size();
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = sum; j >= nums[i-1]; j--) {
                    dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return dp[sum];
    }
};
