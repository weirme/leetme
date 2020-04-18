#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 10010;
int n;
bool graph[N][N] = {0};
bool visited[N] = {0};
int heights[N] = {0};

void dfs(int root, int v, int height) {
    visited[v] = true;
    heights[root] = max(height, heights[root]);
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[v][i]) dfs(root, i, height+1);
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        graph[from][to] = true;
        graph[to][from] = true;
    }
    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, i, 1);
        int idx = find(visited, visited+n, false) - visited;
        if (idx != n) {
            int components = 1;
            while (idx != n) {
                dfs(idx, idx, 1);
                components++;
                idx = find(visited, visited+n, false) - visited;
            }
            cout << "Error: " << components << " components" << endl;
            return 0;
        }
    }
    int maxheight = *max_element(heights, heights+n);
    for (int i = 0; i < n; i++) {
        if (heights[i] == maxheight) cout << i+1 << endl;
    }
	return 0;
}
