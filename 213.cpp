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
private:
    int solve(vector<int>::iterator begin, vector<int>::iterator end) {
        int n = end-begin+1;
        vector<vector<int>> dp(n, {0, *begin});
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + *(begin+i);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
    
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(solve(nums.begin(), nums.end()-2), solve(nums.begin()+1, nums.end()-1));
    }
};
