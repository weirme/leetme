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
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 2; i < nums.size(); i++) {
            if (2 * nums[i-1] == nums[i-2] + nums[i])
                dp[i] = dp[i-1] + 1;
        }
        int res = 0;
        for (auto& v : dp)
            res += v;
        return res;
    }
};
