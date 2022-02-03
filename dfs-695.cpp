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
private:
    int res = 0;
    
    int dfs(vector<vector<int>>& grid, int vi, int vj) {
        if (!(0 <= vi && vi < grid.size()) || !(0 <= vj && vj < grid[0].size()) || grid[vi][vj] == 0) {
            return 0;
        }
        int area = 1;
        grid[vi][vj] = 0;
        area += dfs(grid, vi-1, vj);
        area += dfs(grid, vi+1, vj);
        area += dfs(grid, vi, vj-1);
        area += dfs(grid, vi, vj+1);
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> grid = {{0,0,0,1,1,0,0,0}, {0,0,0,1,1,0,0,0}};
    Solution s;
    int res = s.maxAreaOfIsland(grid);
    return 0;
}
