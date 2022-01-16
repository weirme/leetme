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

/*
 Rules of mod:
    (a op b) % p = ((a % p) op (b % p)) % p
    op: + - *
 */

class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        long long prod = 1;
        int x = n / 3 - 1;
        int y = n % 3;
        
        while (x--) {
            prod *= 3;
            prod %= 1000000007;
        }
        
        if (y == 0) {
            prod *= 3;
            prod %= 1000000007;
        }
        else if (y == 1) {
            prod *= 4;
            prod %= 1000000007;
        }
        else {
            prod *= 6;
            prod %= 1000000007;
        }
        
        return int(prod);
    }
};
