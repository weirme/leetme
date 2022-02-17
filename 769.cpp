#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ma = -1;
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            ma = max(ma, arr[i]);
            if (ma <= i) res++;
        }
        return res;
    }
};
