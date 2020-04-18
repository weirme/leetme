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

string mul2(string n) {
    int t = 0;
    string res;
    for (auto it = n.end() - 1; it >= n.begin(); it--) {
        int i = *it - '0';
        char c = (i * 2 + t) % 10 + '0';
        res.push_back(c);
        t = (i * 2 + t) / 10;
    }
    if (t > 0) res.push_back(t + '0');
    return res;
}

int main() {
    string n1, n2;
    int count[10] = {0};
    cin >> n1;
    n2 = mul2(n1);
    for (auto it = n1.begin(); it < n1.end(); it++) {
        int i = *it - '0';
        count[i]++;
    }
    for (auto it = n2.begin(); it < n2.end(); it++) {
        int i = *it - '0';
        count[i]--;
    }
    int i;
    for (i = 0; i < 10; i++) {
        if (count[i] != 0) break;
    }
    if (i == 10) cout << "Yes" << endl;
    else cout << "No" << endl;
    for (auto it = n2.end()-1; it >= n2.begin(); it--) {
        cout << *it;
    }
    cout << endl;
    return 0;
}

