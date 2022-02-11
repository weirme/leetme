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
        while (q < nums.size()) {
            if (nums[q] != 0) swap(nums[p++], nums[q]);
            q++;
        }
    }
};
