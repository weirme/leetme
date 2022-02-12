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
private:
    double solve(double x, long long n) {
        double res = 1;
        while (n) {
            if (n&1) res *= x;
            n = n>>1;
            x *= x;
        }
        return res;
    }
    
public:
    double myPow(double x, int n) {
        if (x == 0) return 0;
        if (n < 0) return 1 / solve(x, (long long)n * -1);
        return solve(x, n);
    }
};
