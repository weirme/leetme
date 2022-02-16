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
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> dp = {1, 1};
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) dp[0] = dp[1]+1;
            else dp[1] = dp[0]+1;
        }
        return max(dp[0], dp[1]);
    }
};
