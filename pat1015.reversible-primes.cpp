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

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

int toDecimal(vector<int> nr, int radix) {
    int res = 0;
    for (auto it = nr.begin(); it < nr.end(); it++) {
        res = res * radix + *it;
    }
    return res;
}

vector<int> toRadix(int n, int radix) {
    vector<int> res;
    while (n) {
        res.push_back(n % radix);
        n /= radix;
    }
    return res;
}

int main() {
    int n, radix;
    while (1) {
        cin >> n;
        if (n < 0) return 0;
        cin >> radix;
        if (!isPrime(n)) {
            cout << "No" << endl;
            continue;
        }
        vector<int> nr = toRadix(n, radix);
        int r = toDecimal(nr, radix);
        if (!isPrime(r)) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
	return 0;
}
