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
const int N = 1010;

struct AppleTree {
    int num;
    int drop = 0;
    int dropSum = 0;
};

int main() {
    AppleTree trees[N];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m, mi;
        cin >> m;
        cin >> trees[i].num;
        for (int j = 1; j < m; j++) {
            cin >> mi;
            if (mi > 0) {
                if (mi < trees[i].num) trees[i].drop = 1;
                trees[i].num = mi;
            }
            else trees[i].num += mi;
        }
    }
    trees[0].dropSum = trees[n-1].drop + trees[0].drop + trees[1].drop;
    trees[n-1].dropSum = trees[n-2].drop + trees[n-1].drop + trees[0].drop;
    for (int i = 1; i < n-1; i++)
        trees[i].dropSum = trees[i-1].drop + trees[i].drop + trees[i+1].drop;
    int sum0 = 0, sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum0 += trees[i].num;
        sum1 += trees[i].drop;
        sum2 += (trees[i].dropSum == 3);
    }
    cout << sum0 << " " << sum1 << " " << sum2 << endl;
	return 0;
}
