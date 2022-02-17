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
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() <= 2) return 0;
        int left = 0, right = 2;
        int delta = nums[1]-nums[0];
        int res = 0;
        while (right < nums.size()) {
            int d = nums[right]-nums[right-1];
            if (d == delta) res += max(0, right-left-1);
            else {
                left = right-1;
                delta = d;
            }
            right++;
        }
        return res;
    }
};
