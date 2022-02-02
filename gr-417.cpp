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
    vector<vector<bool>> visited1, visited2;
    bool flag1, flag2;
    
    void dfs(vector<vector<int>>& grid, int vi, int vj, vector<vector<bool>>& visited) {
        if (vi < 0 || vj < 0 || vi >= grid.size() || vj >= grid[0].size() || visited[vi][vj])
            return;
        visited[vi][vj] = true;
        if (vi-1 >= 0 && grid[vi-1][vj] >= grid[vi][vj]) dfs(grid, vi-1, vj, visited);
        if (vj-1 >= 0 && grid[vi][vj-1] >= grid[vi][vj]) dfs(grid, vi, vj-1, visited);
        if (vi+1 < grid.size() && grid[vi+1][vj] >= grid[vi][vj]) dfs(grid, vi+1, vj, visited);
        if (vj+1 < grid[0].size() && grid[vi][vj+1] >= grid[vi][vj]) dfs(grid, vi, vj+1, visited);
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        for (int i = 0; i < heights.size(); i++) {
            visited1.push_back(*new vector<bool>(heights[0].size(), false));
            visited2.push_back(*new vector<bool>(heights[0].size(), false));
        }
        vector<vector<int>> res;
        for (int i = 0; i < heights.size(); i++) {
            dfs(heights, i, 0, visited1);
            dfs(heights, i, heights[0].size()-1, visited2);
        }
        for (int j = 0; j < heights[0].size(); j++) {
            dfs(heights, 0, j, visited1);
            dfs(heights, heights.size()-1, j, visited2);
        }
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (visited1[i][j] && visited2[i][j])
                    res.push_back({i, j});
            }
        }
        return res;
    }
};
