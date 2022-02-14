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
        return x[1] < y[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int last = points[0][1];
        int n = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > last) {
                last = points[i][1];
                n++;
            }
        }
        return n;
    }
};
