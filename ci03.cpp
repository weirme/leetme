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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> flags(n);
        flags.assign(n, 0);
        for (int i = 0; i < n; i++) {
            flags[nums[i]]++;
            if (flags[nums[i]] >= 2) {
                return nums[i];
            }
        }
        return -1;
    }
};
