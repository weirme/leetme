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
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> stk;
        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                res[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }
        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                res[stk.top()] = nums[i];
                stk.pop();
            }
        }
        return res;
    }
};
