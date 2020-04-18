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

struct cmp {
    bool operator()(const char* a, const char* b) const {
        return strcmp(a, b) < 0;
    }
};

int main() {
    int n, k;
    map<char*, vector<int>, cmp> mp;
    scanf("%d%d", &n, &k);
    while (k--) {
        int id, m;
        scanf("%d%d", &id, &m);
        getchar();
        while (m--) {
            char* name = new char(5);
            scanf("%s", name);
            if (mp.find(name) == mp.end()) {
                vector<int> tmp = {id};
                mp[name] = tmp;
            }
            else {
                mp[name].push_back(id);
            }
        }
    }
    while (n--) {
        char* name = new char(5);
        scanf("%s", name);
        vector<int> tmp = mp[name];
        sort(tmp.begin(), tmp.end());
        printf("%s %d", name, tmp.size());
        for (auto it = tmp.begin(); it < tmp.end(); it++)
            printf(" %d", *it);
        printf("\n");
    }
	return 0;
}
