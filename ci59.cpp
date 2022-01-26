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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.size() == 0) {
            return res;
        }
        deque<int> que;
        for (int i = 0; i < k; i++) {
            while (!que.empty() && nums[i] > nums[que.back()]) {
                que.pop_back();
            }
            que.push_back(i);
        }
        
        for (int i = k; i < nums.size(); i++) {
            res.push_back(nums[que.front()]);
            while (!que.empty() && nums[i] > nums[que.back()]) {
                que.pop_back();
            }
            if (!que.empty() && que.front() <= i-k) {
                que.pop_front();
            }
            que.push_back(i);
        }
        
        res.push_back(nums[que.front()]);
        return res;
    }
};
