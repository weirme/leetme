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
    int countBinarySubstrings(string s) {
        int last = s[0];
        int cnt0 = 0, cnt1 = 1;
        int res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == last) cnt1++;
            else {
                res += min(cnt0, cnt1);
                cnt0 = cnt1;
                cnt1 = 1;
                last = s[i];
            }
        }
        res += min(cnt0, cnt1);
        return res;
    }
};
