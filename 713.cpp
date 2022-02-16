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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int cur = 1;
        int res = 0;
        while (r < nums.size()) {
            cur *= nums[r];
            while (cur >= k && l <= r) cur /= nums[l++];
            if (l <= r) res += r-l+1;
            r++;
        }
        return res;
    }
};
