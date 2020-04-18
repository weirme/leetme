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

string convert(int n) {
    n--;
    int a = n / 13;
    int b = n % 13;
    string t[5] = {"S", "H", "C", "D", "J"};
    return t[a] + to_string(b+1);
}

int main() {
    int last[55];
    int cur[55];
    for (int i = 1; i <= 54; i++) last[i] = i;
    int k;
    cin >> k;
    int shuffle[55];
    for (int i = 1; i <= 54; i++) cin >> shuffle[i];
    while (k--) {
        for (int i = 1; i <= 54; i++) cur[shuffle[i]] = last[i];
        swap(last, cur);
    }
    for (int i = 1; i <= 54; i++) {
        string str = convert(last[i]);
        cout << str;
        if (i < 54) cout << " ";
    }
	return 0;
}
