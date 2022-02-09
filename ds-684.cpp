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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UFSet set(edges.size());
        for (auto& e : edges) {
            if (set.isconnect(e[0]-1, e[1]-1)) return e;
            set.connect(e[0]-1, e[1]-1);
        }
        return {};
    }
};
