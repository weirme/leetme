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
    vector<int> dir = {-1, 0, 1, 0, -1};
    queue<pair<int, int>> que;
    
    void dfs(vector<vector<int>>& grid, int vi, int vj) {
        if (!(0 <= vi && vi < grid.size()) || !(0 <= vj && vj < grid[0].size())) return;
        if (grid[vi][vj] == 0 || grid[vi][vj] == 2) return;
        grid[vi][vj] = 2;
        que.push({vi, vj});
        for (int i = 0; i < 4; i++) {
            dfs(grid, vi+dir[i], vj+dir[i+1]);
        }
    }
    
    int bfs(vector<vector<int>>& grid) {
        int level = 0;
        while (!que.empty()) {
            int sz = que.size();
            while (sz--) {
                auto [vi, vj] = que.front();
                que.pop();
                for (int k = 0; k < 4; k++) {
                    int i = vi+dir[k], j = vj+ dir[k+1];
                    if (!(0 <= i && i < grid.size()) || !(0 <= j && j < grid[0].size())) continue;
                    if (grid[i][j] == 1) return level;
                    if (grid[i][j] == 2) continue;
                    grid[i][j] = 2;
                    que.push({i, j});
                }
            }
            level++;
        }
        return -1;
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    return bfs(grid);
                }
            }
        }
        return -1;
    }
};
