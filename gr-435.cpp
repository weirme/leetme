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
private:
    bool static cmp(vector<int> x, vector<int> y) {
        return x[1] < y[1];
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        int last = -INF;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] < last) {
                res++;
            }
            else {
                last = intervals[i][1];
            }
        }
        return res;
    }
};
