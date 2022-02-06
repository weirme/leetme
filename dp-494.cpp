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
private:
    void solve(vector<int>& nums, int target, int pos, int cur, int& res) {
        if (pos == nums.size()) {
            res += (cur == target);
            return;
        }
        solve(nums, target, pos+1, cur+nums[pos], res);
        solve(nums, target, pos+1, cur-nums[pos], res);
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int res = 0;
        solve(nums, target, 0, 0, res);
        return res;
    }
};
