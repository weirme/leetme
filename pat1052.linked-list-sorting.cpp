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

struct Node {
    int address;
    int key = INF;
    int next = -1;
    bool flag = false;
} list[N];

bool cmp(Node& a, Node& b) {
    return a.key < b.key;
}

int main() {
    int n, head;
    cin >> n >> head;
    for (int i = 0; i < n; i++) {
        int address, key, next;
        cin >> address >> key >> next;
        list[address] = {address, key, next, false};
    }
    int p = head;
    int len = 0;
    while (p != -1) {
        list[p].flag = true;
        p = list[p].next;
        len++;
    }
    sort(list, list+N, cmp);
    printf("%d ", len);
    p = 0;
    int cur = 0;
    while (cur < len) {
        if (list[p].flag) {
            printf("%05d\n%05d %d ", list[p].address, list[p].address, list[p].key);
            cur++;
        }
        p++;
    }
    printf("-1\n");
	return 0;
}
