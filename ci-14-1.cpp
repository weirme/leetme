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
    int cuttingRope(int n) {
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (n == 3) return 2;
        int x = n/3-1;
        int y = n%3;
        long long res = 1;
        while (x--) {
            res = (res * 3) % 1000000007;
        }
        if (y == 0) res = (res * 3) % 1000000007;
        else if (y == 1) res = (res * 4) % 1000000007;
        else res = (res * 6) % 1000000007;
        return res;
    }
};
