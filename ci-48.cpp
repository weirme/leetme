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
    int lengthOfLongestSubstring(string s) {
        vector<int> last(128, -1);
        int l = 0, r = 0;
        int res = 0;
        while (r < s.size()) {
            if (last[s[r]] < l) {
                res = max(res, r-l+1);
                last[s[r]] = r;
                r++;
            }
            else l++;
        }
        return res;
    }
};
