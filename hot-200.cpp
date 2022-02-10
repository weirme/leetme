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
    void solve(vector<vector<char>>& grid, int vi, int vj) {
        if (!(0 <= vi && vi < grid.size()) || !(0 <= vj && vj < grid[0].size()) || grid[vi][vj] == '0') return;
        grid[vi][vj] = '0';
        solve(grid, vi-1, vj);
        solve(grid, vi+1, vj);
        solve(grid, vi, vj-1);
        solve(grid, vi, vj+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    solve(grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};
