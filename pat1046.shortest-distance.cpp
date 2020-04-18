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
const int N = 100010;

int main() {
    int num[N];
    int sum[N];
    int n, m;
    cin >> n;
    sum[1] = 0;
    for (int i = 2; i <= n+1; i++) {
        cin >> num[i];
        sum[i] = sum[i-1] + num[i];
    }
    cin >> m;
    while (m--) {
        int from, to;
        cin >> from >> to;
        if (from > to) swap(from, to);
        int tmp = sum[to] - sum[from];
        tmp = min(tmp, sum[n+1] - tmp);
        cout << tmp << endl;
    }
	return 0;
}
