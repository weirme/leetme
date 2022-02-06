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
private:
    bool static cmp(vector<int>& x, vector<int>& y) {
        return x[0] < y[0];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(pairs.size(), 1);
        for (int i = 1; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return dp[pairs.size()-1];
    }
};
