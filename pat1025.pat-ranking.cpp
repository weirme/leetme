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

struct Info {
    string id;
    int score;
    int loc;
    int grank;
    int lrank;
    
    Info(string id, int score, int loc) {
        this->id = id;
        this->score = score;
        this->loc = loc;
    }
};

bool cmp(Info& a, Info& b) {
    if (a.score > b.score) return true;
    if (a.score < b.score) return false;
    if (a.loc < b.loc) return true;
    if (a.loc > b.loc) return false;
    if (a.id < b.id) return true;
    return false;
}

int main() {
    int n, k;
    vector<Info> testees;
    string id;
    int score;
    int num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        num += k;
        for (int j = 0; j < k; j++) {
            cin >> id >> score;
            Info tmp(id, score, i);
            testees.push_back(tmp);
        }
    }
    sort(testees.begin(), testees.end(), cmp);
    int global = 0;
    int gpass = 0;
    int glast = -1;
    vector<int> local(n+1, 0);
    vector<int> lpass(n+1, 0);
    vector<int> llast(n+1, -1);
    for (auto it = testees.begin(); it < testees.end(); it++) {
        gpass++;
        if (it->score == glast) it->grank = global;
        else {
            it->grank = gpass;
            global = gpass;
            glast = it->score;
        }
        int i = it->loc;
        lpass[i]++;
        if (it->score == llast[i]) it->lrank = local[i];
        else {
            it->lrank = lpass[i];
            local[i] = lpass[i];
            llast[i] = it->score;
        }
    }
    cout << num << endl;
    for (auto it = testees.begin(); it < testees.end(); it++) {
        cout << it->id << " " << it->grank << " " << it->loc << " " << it->lrank << endl;
    }
	return 0;
}
