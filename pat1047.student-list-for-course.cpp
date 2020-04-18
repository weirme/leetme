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

bool cmp(char* a, char* b) {
    return strcmp(a, b) < 0;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<vector<char*>> list(k+1);
    while (n--) {
        char* name = new char;
        int c, id;
        scanf("%s %d", name, &c);
        while (c--) {
            scanf("%d", &id);
            list[id].push_back(name);
        }
    }
    for (int i = 1; i <= k; i++) {
        auto vec = list[i];
        sort(vec.begin(), vec.end(), cmp);
        printf("%d %d\n", i, vec.size());
        for (auto name : vec) printf("%s\n", name);
    }
	return 0;
}
