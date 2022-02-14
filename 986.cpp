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
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> res;
        while (i < firstList.size() && j < secondList.size()) {
            if (firstList[i][1] < secondList[j][0]) i++;
            else if (firstList[i][0] > secondList[j][1]) j++;
            else {
                res.push_back({max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])});
                if (firstList[i][1] < secondList[j][1]) i++;
                else j++;
            }
        }
        return res;
    }
};
