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
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (edges.size() == 0)
            return {0};
        vector<vector<bool>> graph(n, *new vector<bool>(n, false));
        for (auto& e : edges) {
            graph[e[0]][e[1]] = true;
            graph[e[1]][e[0]] = true;
        }
        vector<int> res;
        int min_h = INF;
        for (int v = 0; v < n; v++) {
            vector<bool> visited(n, false);
            queue<int> que;
            que.push(v);
            visited[v] = true;
            int level = 0;
            while (!que.empty()) {
                int len = que.size();
                while (len--) {
                    int cur = que.front();
                    que.pop();
                    for (int i = 0; i < n; i++) {
                        if (!visited[i] && graph[cur][i] == true) {
                            que.push(i);
                            visited[i] = true;
                        }
                    }
                }
                if (++level > min_h)
                    break;
            }
            if (level == min_h) {
                res.push_back(v);
            }
            if (level < min_h) {
                min_h = level;
                res = {v};
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> edge = {{0,1},{1,2},{2,3},{0,4},{4,5},{4,6},{6,7}};
    Solution s;
    vector<int> res = s.findMinHeightTrees(8, edge);
    return 0;
}
