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
    int i;
    string res;
    while (n) {
        i = n % 13;
        n /= 13;
        if (i < 10) res.push_back(i + '0');
        else res.push_back(i - 10 + 'A');
    }
    while (res.size() < 2) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    cout << '#' << convert(r) << convert(g) << convert(b) << endl;
	return 0;
}
