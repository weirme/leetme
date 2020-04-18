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
const int N = 510;

void printPath(int last[], int v) {
    if (last[v] == v) {
        cout << v << " ";
        return;
    }
    printPath(last, last[v]);
    cout << v << " ";
}

int main() {
    int dist[N][N];
    int cost[N][N];
    int n, m, vs, ve;
    cin >> n >> m >> vs >> ve;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
            cost[i][j] = INF;
        }
    }
    while (m--) {
        int i, j, d, c;
        cin >> i >> j >> d >> c;
        dist[i][j] = d;
        dist[j][i] = d;
        cost[i][j] = c;
        cost[j][i] = c;
    }
    int minDist[N];
    int minCost[N];
    bool visited[N];
    int last[N];
    for (int i = 0; i < n; i++) {
        minDist[i] = dist[vs][i];
        minCost[i] = cost[vs][i];
        visited[i] = false;
        last[i] = vs;
    }
    visited[vs] = true;
    
    while (1) {
        
        int v = vs;
        for (int u = 0; u < n; u++) {
            if (visited[u]) continue;
            if (minDist[u] < minDist[v] || (minDist[u] == minDist[v] && minCost[u] < minCost[v])) {
                v = u;
            }
        }
        
        if (v == vs) break;
        visited[v] = true;
        
        for (int u = 0; u < n; u++) {
            if (visited[u]) continue;
            int dist_j = minDist[v] + dist[v][u];
            int cost_j = minCost[v] + cost[v][u];
            if (dist_j < minDist[u] || (dist_j == minDist[u] && cost_j < minCost[u])) {
                minDist[u] = dist_j;
                minCost[u] = cost_j;
                last[u] = v;
            }
        }
    }
    printPath(last, ve);
    cout << minDist[ve] << " " << minCost[ve] << endl;
	return 0;
}
