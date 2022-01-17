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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

bool isequal(double x, double y) {
    return fabs(x - y) < 1e-8;
}

double unsigned_my_pow(double x, unsigned int n) {
    double res = 1;
    while (n) {
        if (n & 1)
            res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

double myPow(double x, int n) {
    if (isequal(x, 0))
        return 0;
    long long ln = (long long)n;
    unsigned int un;
    if (n < 0) {
        un = (unsigned int)(-ln);
        return 1 / unsigned_my_pow(x, un);
    }
    else {
        un = (unsigned int)ln;
        return unsigned_my_pow(x, un);
    }
}
