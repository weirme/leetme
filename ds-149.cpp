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
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> mp;
            for (int j = i+1; j < points.size(); j++) {
                double k;
                if (points[i][0] == points[j][0]) k = INF;
                else k = (points[i][1] - points[j][1]) * 1.0 / (points[i][0] - points[j][0]);
                res = max(++mp[k], res);
            }
        }
        return res+1;
    }
};
