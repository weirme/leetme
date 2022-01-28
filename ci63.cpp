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
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int vmin = INF;
        for (auto it = prices.begin(); it < prices.end(); it++) {
            res = max(res, *it - vmin);
            vmin = min(vmin, *it);
        }
        return res;
    }
};
