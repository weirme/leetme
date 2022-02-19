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
    int firstMissingPositive(vector<int>& nums) {
        for (auto& n : nums) {
            if (n <= 0) n = INT_MAX;
        }
        for (auto n : nums) {
            int x = abs(n);
            if (1 <= x && x <= nums.size() && nums[x-1] > 0) nums[x-1] *= -1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) return i+1;
        }
        return nums.size()+1;
    }
};
