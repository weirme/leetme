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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        int rl = 0, rh = matrix.size()-1;
        int cl = 0, ch = matrix[0].size()-1;
        vector<int> res;
        while (rl <= rh && cl <= ch) {
            for (int j = cl; j <= ch; j++) {
                res.push_back(matrix[rl][j]);
            }
            if (++rl > rh) break;
            for (int i = rl; i <= rh; i++) {
                res.push_back(matrix[i][ch]);
            }
            if (cl > --ch) break;
            for (int j = ch; j >= cl; j--) {
                res.push_back(matrix[rh][j]);
            }
            if (rl > --rh) break;
            for (int i = rh; i >= rl; i--) {
                res.push_back(matrix[i][cl]);
            }
            if (cl++ > ch) break;
        }
        return res;
    }
};
