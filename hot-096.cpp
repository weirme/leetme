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
    int numTrees(int n) {
        long long res = 1;
        for (int i = 1, j = n+1; i <= n; i++, j++) {
            res = res * j / i;
        }
        res /= n+1;
        return res;
    }
};
