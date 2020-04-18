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
const int N = 1010;

bool graph[N][N] = {0};
bool visited[N] = {0};

void dfs(int v, int n) {
    visited[v] = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && graph[v][i]) dfs(i, n);
    }
    return;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    while (m--) {
        int from, to;
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }
    while (k--) {
        int v;
        cin >> v;
        memset(visited, 0, sizeof(visited));
        visited[v] = true;
        int res = -1;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                res++;
                dfs(i, n);
            }
        }
        cout << res << endl;
    }
	return 0;
}
