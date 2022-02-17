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

struct cmp {
    bool operator()(pair<int, int>& x, pair<int, int>& y) {
        return x.second < y.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int n : nums) mp[n]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
        for (auto [k, v] : mp) {
            que.push({k, v});
        }
        vector<int> res;
        while (k--) {
            res.push_back(que.top().first);
            que.pop();
        }
        return res;
    }
};
