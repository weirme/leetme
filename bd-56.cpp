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
private:
    bool static cmp(vector<int>& x, vector<int>& y) {
        return x[0] < y[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        vector<int> range = intervals[0];
        for (auto v : intervals) {
            if (v[0] <= range[1]) range[1] = max(range[1], v[1]);
            else {
                res.push_back(range);
                range = v;
            }
        }
        res.push_back(range);
        return res;
    }
};
