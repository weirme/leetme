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

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low = 0, high = sqrt(c);
        while (low <= high) {
            long long t = low*low + high*high;
            if (t == c) {
                return true;
            }
            else if (t < c) {
                low++;
            }
            else {
                high--;
            }
        }
        return false;
    }
};
