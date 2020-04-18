#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2010;

struct student {
    int id;
    int score[4];
    int rank[4];
    int best;
} stu[N];

int flag = -1;

bool cmp(student a, student b) {
    return a.score[flag] > b.score[flag];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3;
    }
    for (flag = 0; flag < 4; flag++) {
        sort(stu, stu+n, cmp);
        stu[0].rank[flag] = 1;
        for (int i = 1; i < n; i++) {
            if (stu[i].score[flag] == stu[i-1].score[flag])
                stu[i].rank[flag] = stu[i-1].rank[flag];
            else stu[i].rank[flag] = i+1;
        }
    }
    int exist[1000000];
    memset(exist, -1, sizeof(exist));
    for (int i = 0; i < n; i++) {
        exist[stu[i].id] = i;
        int minrank = stu[i].rank[0];
        stu[i].best = 0;
        for (flag = 1; flag < 4; flag++) {
            if (stu[i].rank[flag] < minrank) {
                minrank = stu[i].rank[flag];
                stu[i].best = flag;
            }
        }
    }
    char names[4] = {'A', 'C', 'M', 'E'};
    int id;
    while (m--) {
        cin >> id;
        int temp = exist[id];
        if (temp == -1) cout << "N/A" << endl;
        else {
            int best = stu[temp].best;
            cout << stu[temp].rank[best] << " " << names[best] << endl;
        }
    }
    return 0;
}
