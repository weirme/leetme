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
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int a = nums[0], b = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            swap(a, b);
            b = max(b+nums[i], a);
        }
        return b;
    }
};
