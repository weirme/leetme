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
const int N = 100010;

int main() {
    int num[N];
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> num[i];
    int nearest = INF;
    vector<pair<int, int>> res;
    int front = 1, rear = 1;
    int cur = num[front];
    while (rear <= n) {
        if (cur < m)
            cur += num[++rear];
        else if (cur == m) {
            if (cur - m < nearest - m) {
                nearest = cur;
                res.clear();
            }
            res.push_back(make_pair(front, rear));
            nearest = m;
            cur -= num[front++];
            cur += num[++rear];
        }
        else {
            if (cur - m < nearest - m) {
                nearest = cur;
                res.clear();
                res.push_back(make_pair(front, rear));
            }
            else if (cur == nearest) res.push_back(make_pair(front, rear));
            cur -= num[front++];
            if (front > rear) cur += num[++rear];
        }
    }
    for (auto it = res.begin(); it < res.end(); it++)
        cout << it->first << "-" << it->second << endl;
	return 0;
}
