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
    queue<pair<int, int>> que;
    
    void dfs(vector<vector<int>>& grid, int vi, int vj) {
        if (!(0 <= vi && vi < grid.size()) || !(0 <= vj && vj < grid[0].size()))
            return;
        if (grid[vi][vj] != 1)
            return;
        grid[vi][vj] = 2;
        que.push({vi, vj});
        dfs(grid, vi-1, vj);
        dfs(grid, vi+1, vj);
        dfs(grid, vi, vj-1);
        dfs(grid, vi, vj+1);
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int dir[] = {-1, 0, 1, 0, -1};
        int flag = false;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        int level = 0;
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                auto [vi, vj] = que.front();
                que.pop();
                for (int k = 0; k < 4; k++) {
                    int i = vi + dir[k];
                    int j = vj + dir[k+1];
                    if (!(0 <= i && i < grid.size()) || !(0 <= j && j < grid[0].size()) || grid[i][j] == 2) {
                        continue;
                    }
                    if (grid[i][j] == 0) {
                        grid[i][j] = 2;
                        que.push({i, j});
                    }
                    else if (grid[i][j] == 1) {
                        return level;
                    }
                }
            }
            level++;
        }
        return 0;
    }
};

int main() {
    vector<vector<int>> grid = {{0,1}, {1,0}};
    Solution s;
    int res = s.shortestBridge(grid);
    return 0;
}
