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
    int maxSubArray(vector<int>& nums) {
        int res = -INF;
        int sum = 0;
        for (auto it = nums.begin(); it < nums.end(); it++) {
            sum += *it;
            if (sum > res)
                res = sum;
            if (sum < 0)
                sum = 0;
        }
        return res;
    }
};
