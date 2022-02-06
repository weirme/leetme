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
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int cur = 0;
        for (int i = 0; i < arr.size(); i++) {
            cur = max(arr[i], cur);
            if (i == cur) res++;
        }
        return res;
    }
};
