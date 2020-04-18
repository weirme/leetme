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
    string str;
    cin >> str;
    int n = str.size();
    int n1, n2, n3;
    n1 = n3 = (n + 2) / 3;
    n2 = n + 2 - n1 - n3;
    auto front = str.begin(), rear = str.end() - 1;
    for (int i = 1; i < n1; i++) {
        cout << *front++;
        for (int j = 0; j + 2 < n2; j++) cout << " ";
        cout << *rear--;
        cout << endl;
    }
    while (front <= rear) cout << *front++;
    cout << endl;
	return 0;
}
