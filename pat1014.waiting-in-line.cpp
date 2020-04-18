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
const int N = 25;
const int K = 1010;
queue<int> que[N];

struct guest {
    int time;
    int start;
} guests[K];

int main() {
    int n, m, k, q;
    int cntWait = 0;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < k; i++) {
        scanf("%d", &guests[i].time);
        if (cntWait < n * m) {
            que[cntWait%n].push(i);
            guests[i].start = 0;
            cntWait++;
        }
    }
    for (int i = 0; i < k; i++) {
        int tMin = INF;
        int quei = 0;
        for (int j = 0; j < n; j++) {
            if (que[j].empty()) continue;
            int t = que[j].front();
            int finish = guests[t].start + guests[t].time;
            if (finish < tMin) {
                tMin = finish;
                quei = j;
            }
        }
        que[quei].pop();
        if (!que[quei].empty()) {
            int next = que[quei].front();
            guests[next].start = tMin;
        }
        if (cntWait < k) {
            que[quei].push(cntWait);
            cntWait++;
        }
    }
    while (q--) {
        int idx;
        scanf("%d", &idx);
        idx--;
        if (guests[idx].start >= 540) {
            printf("Sorry\n");
            continue;
        }
        int finish = guests[idx].start + guests[idx].time;
        int h = finish / 60 + 8;
        int min = finish % 60;
        printf("%02d:%02d\n", h, min);
    }
	return 0;
}
