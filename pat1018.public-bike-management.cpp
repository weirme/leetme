#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAX = 0xffff;

void print(int i, vector<int>& last) {
    if (i == 0) cout << "0";
    else {
        print(last[i], last);
        cout << "->" << i;
    }
}

int main() {
    int C, N, S, M;
    cin >> C >> N >> S >> M;
    vector<int> vertex(N+1);
    for (int i = 1; i <= N; i++) {
        int t;
        cin >> t;
        vertex[i] = t - C/2;
    }
    vector< vector<int> > graph(N+1, vector<int>(N+1, MAX));
    for (int k = 0; k < M; k++) {
        int i, j, t;
        cin >> i >> j >> t;
        graph[i][j] = t;
        graph[j][i] = t;
    }
    vector<int> last(N+1, 0);
    vector<int> cost(vertex);
    vector<int> dp = graph[0];
    auto it = min_element(dp.begin(), dp.end());
    int i = it - dp.begin();
    last[i] = 0;
    while (i != S) {
        for (int j = 0; j <= N; j++) {
            if (dp[j] == MAX+1) continue;
            int t = dp[i] + graph[i][j];
            if (t < dp[j] || (t == dp[j] && abs(cost[i] + vertex[j]) <= abs(cost[j]))) {
                dp[j] = t;
                last[j] = i;
                cost[j] = cost[i] + vertex[j];
            }
        }
        *it = MAX+1;
        it = min_element(dp.begin(), dp.end());
        i = it - dp.begin();
    }
    cout << -min(cost[S], 0) << " ";
    print(S, last);
    cout << " " << max(cost[S], 0);
    return 0;
}
