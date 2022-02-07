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
    int nthUglyNumber(int n) {
        vector<int> vec(n);
        int p = 0, q = 0, r = 0;
        vec[0] = 1;
        for (int i = 1; i < n; i++) {
            int mi = min(vec[p]*2, min(vec[q]*3, vec[r]*5));
            if (vec[p]*2 == mi) p++;
            if (vec[q]*3 == mi) q++;
            if (vec[r]*5 == mi) r++;
            vec[i] = mi;
        }
        return vec[n-1];
    }
};
