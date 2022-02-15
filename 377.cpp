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
#include <unordered_set>
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] <= i && dp[i-nums[j]] < INF-dp[i]) dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
