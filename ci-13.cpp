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
private:
    int func(int x) {
        int res = 0;
        while (x) {
            res += x%10;
            x /= 10;
        }
        return res;
    }
    
    void solve(vector<vector<int>>& matrix, int vi, int vj, int k, int& res) {
        if (!(0 <= vi && vi < matrix.size()) || !(0 <= vj && vj < matrix[0].size())) return;
        if (matrix[vi][vj] > k) return;
        matrix[vi][vj] = k+1;
        res++;
        solve(matrix, vi-1, vj, k, res);
        solve(matrix, vi+1, vj, k, res);
        solve(matrix, vi, vj-1, k, res);
        solve(matrix, vi, vj+1, k, res);
    }
public:
    int movingCount(int m, int n, int k) {
        vector<vector<int>> matrix(m, *new vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = func(i) + func(j);
            }
        }
        int res = 0;
        solve(matrix, 0, 0, k, res);
        return res;
    }
};
