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
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> stk;
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int top = stk.top();
                stk.pop();
                int l = stk.top()+1;
                int r = i-1;
                res = max(res, heights[top] * (r-l+1));
            }
            stk.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> heights = {5,4,7,1,2,9,8,3,6,4,4,3,2,8,1,9,1};
    Solution s;
    int res = s.largestRectangleArea(heights);
    return 0;
}
