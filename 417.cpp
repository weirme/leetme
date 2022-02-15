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
    void solve(vector<vector<int>>& heights, vector<vector<bool>>& visited, int vi, int vj) {
        static vector<int> dir = {-1, 0, 1, 0, -1};
        visited[vi][vj] = true;
        for (int k = 0; k < 4; k++) {
            int i = vi+dir[k];
            int j = vj+dir[k+1];
            if (0 <= i && i < heights.size() && 0 <= j && j < heights[0].size()
                && !visited[i][j] && heights[vi][vj] <= heights[i][j])
                solve(heights, visited, i, j);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited1(m, *new vector<bool>(n, false));
        vector<vector<bool>> visited2(m, *new vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            solve(heights, visited1, i, 0);
            solve(heights, visited2, i, n-1);
        }
        for (int j = 0; j < n; j++) {
            solve(heights, visited1, 0, j);
            solve(heights, visited2, m-1, j);
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited1[i][j] && visited2[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
