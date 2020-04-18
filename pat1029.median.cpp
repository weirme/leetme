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

int main() {
    int m, n;
    cin >> m;
    vector<long long> vec1(m);
    for (int i = 0; i < m; i++) scanf("%lld", &vec1[i]);
    cin >> n;
    vector<long long> vec2(n);
    for (int i = 0; i < n; i++) scanf("%lld", &vec2[i]);
    int mid = (m + n + 1) / 2;
    auto it1 = vec1.begin(), it2 = vec2.begin();
    int cur = 0;
    while (it1 < vec1.end() && it2 < vec2.end()) {
        cur++;
        if (*it1 < *it2) {
            if (cur == mid) {
                printf("%lld\n", *it1);
                break;
            }
            it1++;
        }
        else {
            if (cur == mid) {
                printf("%lld\n", *it2);
                break;
            }
            it2++;
        }
    }
    while (it1 < vec1.end()) {
        cur++;
        if (cur == mid) {
            printf("%lld", *it1);
            break;
        }
        it1++;
    }
    while (it2 < vec2.end()) {
        cur++;
        if (cur == mid) {
            printf("%lld", *it2);
            break;
        }
        it2++;
    }
	return 0;
}
