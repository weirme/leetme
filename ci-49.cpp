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
    int nthUglyNumber(int n) {
        int p = 0, q = 0, r = 0;
        vector<int> res(n, 1);
        for (int i = 1; i < n; i++) {
            int x = min(res[p]*2, min(res[q]*3, res[r]*5));
            res[i] = x;
            if (x == res[p]*2) p++;
            if (x == res[q]*3) q++;
            if (x == res[r]*5) r++;
        }
        return res[n-1];
    }
};
