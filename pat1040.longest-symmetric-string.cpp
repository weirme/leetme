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

int main() {
    int dp[N][N];
    string str;
    getline(cin, str);
    int n = str.size();
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n-1; i++) {
        if (str[i] == str[i+1]) dp[i][i+1] = 2;
    }
    for (int k = 2; k < n; k++) {
        for (int i = 0; i < n-k; i++) {
            int j = i + k;
            if (str[i] == str[j] && dp[i+1][j-1] > 0) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = 0;
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) res = max(res, dp[i][j]);
    }
    cout << res << endl;
	return 0;
}
