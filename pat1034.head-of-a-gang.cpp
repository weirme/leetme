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
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2010;
map<string, int> mp;
string vertex[N];
int cluster[N] = {0};
int weights[N] = {0};
int weightsall[N] = {0};
int graph[N][N];
int nVertex;

void dfs(int v, int c) {
    cluster[v] = c;
    for (int i = 0; i < nVertex; i++) {
        if (cluster[i] == 0 && graph[v][i] != INF) dfs(i, c);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) graph[i][j] = INF;
    }
    while (n--) {
        string from, to;
        int weight;
        cin >> from >> to >> weight;
        if (mp.find(from) == mp.end()) {
            mp[from] = nVertex;
            vertex[nVertex] = from;
            nVertex++;
        }
        if (mp.find(to) == mp.end()) {
            mp[to] = nVertex;
            vertex[nVertex] = to;
            nVertex++;
        }
        int ifrom = mp[from], ito = mp[to];
        graph[ifrom][ito] = weight;
        weights[ifrom] += weight;
        weightsall[ifrom] += weight;
        weightsall[ito] += weight;
    }
    int c = 1;
    for (int i = 0; i < nVertex; i++) {
        if (cluster[i] == 0) {
            dfs(i, c);
            c++;
        }
    }
    vector<pair<string, int>> res;
    for (int i = 1; i < c; i++) {
        int sum = 0;
        int maxi = -1;
        int num = 0;
        for (int v = 0; v < nVertex; v++) {
            if (cluster[v] == i) {
                sum += weights[v];
                num++;
                if (maxi == -1 || weightsall[v] > weightsall[maxi]) maxi = v;
            }
        }
        if (sum > k && num > 2) res.push_back(make_pair(vertex[maxi], num));
    }
    sort(res.begin(), res.end());
    int nGang = res.size();
    cout << nGang << endl;
    for (auto it = res.begin(); it < res.end(); it++)
        cout << it->first << " " << it->second << endl;
	return 0;
}
