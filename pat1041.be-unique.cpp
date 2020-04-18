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
const int N = 10010;
int flag[N] = {0};

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto it = vec.begin(); it < vec.end(); it++) {
        cin >> *it;
        flag[*it]++;
    }
    for (auto it = vec.begin(); it < vec.end(); it++) {
        if (flag[*it] == 1) {
            cout << *it << endl;
            return 0;
        }
    }
    cout << "None" << endl;
	return 0;
}
