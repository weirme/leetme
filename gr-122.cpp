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
        int last = prices[0];
        int res = 0;
        int i;
        for (i = 0; i < prices.size()-1; i++) {
            if (prices[i] >= prices[i+1]) {
                res += prices[i] - last;
                last = prices[i+1];
            }
        }
        res += max(0, prices[i]-last);
        return res;
    }
};
