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
        deque<int> que;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!que.empty() && nums[que.back()] < nums[i]) {
                que.pop_back();
            }
            que.push_back(i);
            if (i+1 >= k) {
                res.push_back(nums[que.front()]);
                if (que.front()+k-1 <= i) que.pop_front();
            }
        }
        return res;
    }
};
