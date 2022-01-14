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
        size_t n = nums.size();
        for (int i = 0; i < n; i++) {
            int t = nums[i];
            while (t != i) {
                if (nums[t] == t)
                    return t;
                nums[i] = nums[t];
                nums[t] = t;
                t = nums[i];
            }
        }
        return -1;
    }
};
