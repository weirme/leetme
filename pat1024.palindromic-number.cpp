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

string add(string& n) {
    string res;
    int i1, i2;
    int t = 0;
    char c;
    auto it1 = n.begin(), it2 = n.end()-1;
    while (it1 < n.end()) {
        i1 = *it1 - '0';
        i2 = *it2 - '0';
        c = (i1 + i2 + t) % 10 + '0';
        t = (i1 + i2 + t) / 10;
        res.push_back(c);
        it1++;
        it2--;
    }
    if (t > 0) res.push_back(t + '0');
    reverse(res.begin(), res.end());
    return res;
}

bool isPalindromic(string& n) {
    auto front = n.begin(), rear = n.end()-1;
    while (front < rear) {
        if (*front != *rear) return false;
        front++;
        rear--;
    }
    return true;
}

int main() {
    string n;
    int k, i;
    cin >> n >> k;
    for (i = 0; i < k; i++) {
        if (isPalindromic(n)) break;
        n = add(n);
    }
    cout << n << endl << i << endl;
	return 0;
}
