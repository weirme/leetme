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
const int M = 210;
const int L = 10010;

int main() {
    int dp[L] = {0};
    int n, m, l;
    int favs[M];
    int stripe[L];
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) cin >> favs[i];
    cin >> l;
    for (int i = 0; i < l; i++) cin >> stripe[i];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            if (favs[i] == stripe[j]) {
                dp[j] = max(dp[j-1] + 1, dp[j]);
            }
            else {
                dp[j] = max(dp[j-1], dp[j]);
            }
        }
    }
    cout << dp[l-1] << endl;
	return 0;
}
