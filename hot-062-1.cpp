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
    int uniquePaths(int m, int n) {
        long long res = 1;
        for (int i = n, j = 1; j < m; i++, j++) {
            res = res * i / j;
        }
        return res;
    }
};
