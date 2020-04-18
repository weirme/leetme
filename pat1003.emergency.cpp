#include <iostream>

using namespace std;
const int N = 510;
const int MAX = 0x7fffff;
int vertex[N];
bool visited[N] = {0};
int graph[N][N];
int minCost = MAX;
int maxTeams = 0;
int nPath = 1;
int n, m;
int vstart, vend;

void dfs(int v, int cost, int teams) {
    visited[v] = true;
    teams += vertex[v];
    if (v == vend) {
        if (cost < minCost) {
            minCost = cost;
            maxTeams = teams;
            nPath = 1;
        } else if (cost == minCost) {
            nPath++;
            if (teams > maxTeams) maxTeams = teams;
        }
    }
    for (int i = 0; i < n; i++)
        if (!visited[i] && graph[v][i] != MAX) dfs(i, cost + graph[v][i], teams);
    visited[v] = false;
}

int main() {
    cin >> n >> m >> vstart >> vend;
    for (int i = 0; i < n; i++) cin >> vertex[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            graph[i][j] = MAX;
    }
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = cost;
        graph[to][from] = cost;
    }
    dfs(vstart, 0, 0);
    cout << nPath << " " << maxTeams;
    return 0;
}
