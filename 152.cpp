#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp = {nums[0], nums[0]};
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0) {
                dp[0] = max(dp[0]*nums[i], nums[i]);
                dp[1] = min(dp[1]*nums[i], nums[i]);
            }
            else if (nums[i] < 0) {
                int t = dp[0];
                dp[0] = max(dp[1]*nums[i], nums[i]);
                dp[1] = min(t*nums[i], nums[i]);
            }
            else {
                dp[0] = dp[1] = 0;
            }
            res = max(res, dp[0]);
        }
        return res;
    }
};
