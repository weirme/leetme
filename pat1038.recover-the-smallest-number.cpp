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

bool cmp(string a, string b) {
    return a + b < b + a;
}

int main() {
    int n;
    cin >> n;
    vector<string> segs(n);
    for (int i = 0; i < n; i++) cin >> segs[i];
    sort(segs.begin(), segs.end(), cmp);
    string res;
    for (auto it = segs.begin(); it < segs.end(); it++) res += *it;
    auto it = res.begin();
    while (*it == '0') it++;
    if (it == res.end()) cout << 0;
    while (it < res.end()) cout << *it++;
    cout << endl;
	return 0;
}
