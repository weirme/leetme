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
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int top = stk.top();
                stk.pop();
                if (!stk.empty()) {
                    res += (min(height[stk.top()], height[i]) - height[top]) * (i-stk.top()-1);
                }
            }
            stk.push(i);
        }
        return res;
    }
};
