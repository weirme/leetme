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
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);
        int res = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (last[s[i]] < i-cur) cur++;
            else cur = i-last[s[i]];
            res = max(res, cur);
            last[s[i]] = i;
        }
        return res;
    }
};
