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

struct Record {
    char id[7];
    char name[9];
    int score;
};

int c;

bool cmp(Record& a, Record& b) {
    switch (c) {
        case 1:
            return strcmp(a.id, b.id) < 0;
        case 2:
            if (strcmp(a.name, b.name) < 0) return true;
            if (strcmp(a.name, b.name) > 0) return false;
            return strcmp(a.id, b.id) < 0;
        case 3:
            if (a.score < b.score) return true;
            if (a.score > b.score) return false;
            return strcmp(a.id, b.id) < 0;
    }
    return false;
}

int main() {
    int n;
    cin >> n >> c;
    vector<Record> records(n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d", records[i].id, records[i].name, &records[i].score);
    }
    sort(records.begin(), records.end(), cmp);
    for (auto it = records.begin(); it < records.end(); it++) {
        printf("%s %s %d\n", it->id, it->name, it->score);
    }
	return 0;
}
