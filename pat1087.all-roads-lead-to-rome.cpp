#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAX = 0xffff;

int N, K;
map<string, int> dict;
vector<string> names;
int vstart = 0;
int vend;

int minCost = MAX;
int maxHappiness = 0;
int passedNum = MAX;
int nPath = 1;
vector<int> bestPath;

void dfs(vector<int>& vertex, vector<bool> visited, vector< vector<int> >& graph, vector<int>& path, int v, int nPassed, int cost, int happiness) {
    if (cost > minCost) return;
    visited[v] = true;
    path.push_back(v);
    nPassed += 1;
    happiness += vertex[v];
    if (v == vend) {
        if (cost == minCost) nPath++;
        if (cost < minCost || (cost == minCost && (happiness > maxHappiness || (happiness == maxHappiness && nPassed < passedNum)))) {
            minCost = cost;
            maxHappiness = happiness;
            passedNum = nPassed;
            bestPath.assign(path.begin(), path.end());
        }
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i] && graph[v][i] != MAX) dfs(vertex, visited, graph, path, i, nPassed, cost+graph[v][i], happiness);
    }
    path.pop_back();
}

int main() {
    string s;
    int t;
    cin >> N >> K >> s;
    vector<int> vertex(N, 0);
    vector< vector<int> > graph(N, vector<int>(N, MAX));
    dict[s] = 0;
    names.push_back(s);
    for (int i = 1; i < N; i++) {
        cin >> s >> t;
        dict[s] = i;
        names.push_back(s);
        if (s == "ROM") vend = i;
        vertex[i] = t;
    }
    for (int i = 0; i < K; i++) {
        string from, to;
        cin >> from >> to >> t;
        graph[dict[from]][dict[to]] = t;
        graph[dict[to]][dict[from]] = t;
    }
    vector<int> path;
    dfs(vertex, vector<bool>(N, false), graph, path, vstart, 0, 0, 0);
    cout << nPath << " " << minCost << " " << maxHappiness << " " << maxHappiness / (passedNum-1) << endl;
    cout << names[bestPath[0]];
    for (auto it = bestPath.begin()+1; it < bestPath.end(); it++)
        cout << "->" << names[*it];
    return 0;
}
