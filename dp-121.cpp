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
    int maxProfit(vector<int>& prices) {
        int _min = INF;
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < _min) _min = prices[i];
            else res = max(res, prices[i]-_min);
        }
        return res;
    }
};
