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
const int N = 100000;

struct Node {
    int next = -1;
    bool flag = false;
};

int main() {
    Node list[N];
    int front1, front2, n;
    scanf("%d%d%d", &front1, &front2, &n);
    int cur, next;
    char c;
    while (n--) {
        scanf("%d %c %d", &cur, &c, &next);
        list[cur].next = next;
    }
    int idx = front1;
    while (idx != -1) {
        list[idx].flag = true;
        idx = list[idx].next;
    }
    idx = front2;
    while (idx != -1) {
        if (list[idx].flag) {
            printf("%05d\n", idx);
            return 0;
        }
        idx = list[idx].next;
    }
    printf("-1\n");
	return 0;
}
