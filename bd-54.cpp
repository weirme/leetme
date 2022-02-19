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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int ilow = 0, ihigh = m-1;
        int jlow = 0, jhigh = n-1;
        while (1) {
            if (jlow > jhigh) break;
            for (int j = jlow; j <= jhigh; j++) res.push_back(matrix[ilow][j]);
            ilow++;
            if (ilow > ihigh) break;
            for (int i = ilow; i <= ihigh; i++) res.push_back(matrix[i][jhigh]);
            jhigh--;
            if (jlow > jhigh) break;
            for (int j = jhigh; j >= jlow; j--) res.push_back(matrix[ihigh][j]);
            ihigh--;
            if (ilow > ihigh) break;
            for (int i = ihigh; i >= ilow; i--) res.push_back(matrix[i][jlow]);
            jlow++;
        }
        return res;
    }
};
