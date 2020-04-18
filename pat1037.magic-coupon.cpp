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

int main() {
    int c, p;
    cin >> c;
    vector<int> coupons(c);
    for (int i = 0; i < c; i++) cin >> coupons[i];
    cin >> p;
    vector<int> products(p);
    for (int i = 0; i < p; i++) cin >> products[i];
    sort(coupons.begin(), coupons.end());
    sort(products.begin(), products.end());
    vector<int>::iterator it1 = coupons.begin(), it2 = products.begin();
    int sum = 0;
    while (*it1 < 0 && *it2 < 0) {
        sum += *it1 * *it2;
        it1++;
        it2++;
    }
    it1 = coupons.end()-1, it2 = products.end()-1;
    while (*it1 > 0 && *it2 > 0) {
        sum += *it1 * *it2;
        it1--;
        it2--;
    }
    cout << sum << endl;
	return 0;
}
