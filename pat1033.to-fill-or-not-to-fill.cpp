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
const int N = 30010;

struct Station {
    float price;
    int dist;
};

bool cmp(Station& a, Station& b) {
    return a.price < b.price;
}

int main() {
    int cap, dist, cost, n;
    scanf("%d%d%d%d", &cap, &dist, &cost, &n);
    bool reach[N] = {0};
    vector<Station> sta(n);
    float sum = 0;
    for (int i = 0; i < n; i++) scanf("%f%d", &sta[i].price, &sta[i].dist);
    sort(sta.begin(), sta.end(), cmp);
    for (auto it = sta.begin(); it < sta.end(); it++) {
        int d = 0;
        for (int i = it->dist; i < min(it->dist + cap * cost, dist); i++) {
            if (!reach[i]) {
                reach[i] = true;
                d++;
            }
        }
        sum += d* it->price;
    }
    sum /= cost;
    int dmax = find(reach, reach+dist, false) - reach;
    if (dmax != dist) printf("The maximum travel distance = %.2f", float(dmax));
    else printf("%.2f", sum);
	return 0;
}
