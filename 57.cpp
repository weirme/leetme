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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto it = intervals.begin();
        while (it < intervals.end() && (*it)[0] < newInterval[0]) it++;
        intervals.insert(it, newInterval);
        vector<vector<int>> res;
        vector<int> range = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= range[1]) range[1] = max(range[1], intervals[i][1]);
            else {
                res.push_back(range);
                range = intervals[i];
            }
        }
        res.push_back(range);
        return res;
    }
};
