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
    vector<bool> visited;
    
    void dfs(vector<vector<int>>& graph, int v) {
        visited[v] = true;
        for (int i = 0; i < graph.size(); i++) {
            if (v != i && graph[v][i] == 1 && !visited[i]) {
                dfs(graph, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        for (int i = 0; i < isConnected.size(); i++) {
            visited.push_back(false);
        }
        int res = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                res++;
                dfs(isConnected, i);
            }
        }
        return res;
    }
};
