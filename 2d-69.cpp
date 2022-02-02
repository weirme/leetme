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
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int low = 1, high = x/2;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            long long p = mid * mid;
            long long q = (mid+1) * (mid+1);
            if (p <= x && q > x)
                return mid;
            else if (p <= x)
                low = mid+1;
            else
                high = mid-1;
        }
        return 0;
    }
};
