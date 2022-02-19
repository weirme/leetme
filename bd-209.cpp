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

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sum = 0;
        int res = INT_MAX;
        while (r < nums.size()) {
            sum += nums[r];
            while (l <= r && sum >= target) {
                res = min(res, r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return res == INT_MAX ? 0 : res;
    }
};
