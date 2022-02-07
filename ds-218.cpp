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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> que;
        vector<int> res;
        int low = 0, high = 0;
        while (high < nums.size()) {
            while (!que.empty() && nums[que.back()] < nums[high]) {
                que.pop_back();
            }
            que.push_back(high);
            
            if (high >= k-1) {
                res.push_back(nums[que.front()]);
                if (que.front() == low) que.pop_front();
                low++;
            }
            high++;
        }
        return res;
    }
};
