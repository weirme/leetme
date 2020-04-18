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

vector<int> decimal2base(int n, int b) {
    vector<int> res;
    while (n) {
        res.push_back(n % b);
        n /= b;
    }
    return res;
}

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> digits = decimal2base(n, b);
    auto front = digits.begin(), rear = digits.end()-1;
    while (front < rear) {
        if (*front != *rear) break;
        front++;
        rear--;
    }
    if (front < rear) cout << "No" << endl;
    else cout << "Yes" << endl;
    for (auto it = digits.end()-1; it > digits.begin(); it--)
        cout << *it << " ";
    cout << *digits.begin() << endl;
	return 0;
}
