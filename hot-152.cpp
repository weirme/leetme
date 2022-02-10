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
    int maxProduct(vector<int>& nums) {
        int ma = nums[0], mi = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int t = ma;
            ma = max(nums[i], max(ma*nums[i], mi*nums[i]));
            mi = min(nums[i], min(t*nums[i], mi*nums[i]));
            res = max(res, ma);
        }
        return res;
    }
};
