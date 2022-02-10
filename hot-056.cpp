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
private:
    bool static cmp(vector<int>& x, vector<int>& y) {
        return x[0] < y[0];
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<int> range = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= range[1]) {
                range[1] = max(range[1], intervals[i][1]);
            }
            else {
                res.push_back(range);
                range = intervals[i];
            }
        }
        res.push_back(range);
        return res;
    }
};
