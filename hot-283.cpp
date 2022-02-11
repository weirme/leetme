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
    void moveZeroes(vector<int>& nums) {
        int p = 0, q = 0;
        while (p < nums.size()) {
            if (nums[p] != 0) nums[q++] = nums[p];
            p++;
        }
        while (q < nums.size()) {
            nums[q++] = 0;
        }
    }
};
