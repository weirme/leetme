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
const int N = 110;

class Solution {
private:
    int f[N] = {0, 1};
public:
    int fib(int n) {
        for (int i = 2; i <= n; i++) {
            f[i] = (f[i-1] + f[i-2]) % int(1e9 + 7);
        }
        return f[n];
    }
};
