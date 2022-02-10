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
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!stk.empty() && height[stk.top()] <= height[i]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                res += (min(height[left], height[i]) - height[top]) * (i-left-1);
            }
            stk.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    int res = s.trap(height);
    return 0;
}
