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
    vector<vector<int>> findContinuousSequence(int target) {
        int low = 1, high = 1;
        int cur = 1;
        vector<vector<int>> res;
        while (low <= (target+1)/2) {
            if (cur == target && high-low+1 >= 2) {
                vector<int> sol;
                for (int i = low; i <= high; i++) sol.push_back(i);
                res.push_back(sol);
                cur -= low++;
                cur += ++high;
            }
            else if (cur < target) cur += ++high;
            else cur -= low++;
        }
        return res;
    }
};
