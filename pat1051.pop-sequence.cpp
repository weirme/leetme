#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<int> vec(n);
    while (k--) {
        for (int i = 0; i < n; i++) cin >> vec[i];
        int max_ = 0;
        int cur = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (vec[i] - i > m) {
                flag = false;
                break;
            }
            if (vec[i] < max_ && vec[i] > cur) {
                flag = false;
                break;
            }
            if (vec[i] > max_) {
                max_ = vec[i];
                cur = max_ - 1;
            }
            else cur = vec[i];
            
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}
