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
    vector<int> countBits(int n) {
        if (n == 0) return {0};
        vector<int> res(n+1, 0);
        res[1] = 1;
        unsigned int cur = 2;
        unsigned int mod = 0x1;
        for (unsigned int i = 2; i <= n; i++) {
            res[i] = 1 + res[i&mod];
            if (cur<<1 == i+1) {
                cur = cur<<1;
                mod = (mod<<1) | 0x1;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> res = s.countBits(5);
    return 0;
}
