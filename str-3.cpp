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

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(128, -1);
        int cur = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] < i - cur) cur++;
            else {
                res = max(res, cur);
                cur = i-mp[s[i]];
            }
            mp[s[i]] = i;
        }
        res = max(res, cur);
        return res;
    }
};
