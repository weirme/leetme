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
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int v) {
        visited[v] = true;
        for (int i = 0; i < graph.size(); i++) {
            if (graph[v][i] == 1 && !visited[i]) dfs(graph, visited, i);
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                dfs(isConnected, visited, v);
                res++;
            }
        }
        return res;
    }
};
