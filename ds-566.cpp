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
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (m * n != r * c) return mat;
        vector<vector<int>> res(r, *new vector<int>(c));
        for (int k = 0; k < m * n; k++) {
            int i1 = k / n, j1 = k % n;
            int i2 = k / c, j2 = k % c;
            res[i2][j2] = mat[i1][j1];
        }
        return res;
    }
};
