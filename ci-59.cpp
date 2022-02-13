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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> stk;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && nums[stk.back()] < nums[i]) {
                stk.pop_back();
            }
            stk.push_back(i);
            if (i+1 >= k) res.push_back(nums[stk.front()]);
            if (i-stk.front()+1 >= k) stk.pop_front();
        }
        return res;
    }
};
