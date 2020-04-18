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

bool flag = false;

vector<int>::iterator search(vector<int>::iterator front, vector<int>::iterator rear, int val) {
    vector<int>::iterator mid;
    while (front <= rear) {
        mid = front + (rear - front) / 2;
        if (*mid < val) front = mid + 1;
        else if (*mid > val) rear = mid - 1;
        else {
            flag = true;
            return mid;
        }
    }
    return mid;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> num(n);
    for (int i = 0; i < n; i++) cin >> num[i];
    sort(num.begin(), num.end());
    for (auto it = num.begin(); it < num.end(); it++) {
        auto remain = search(it + 1, num.end() - 1, m - *it);
        if (flag) {
            cout << *it << " " << *remain << endl;
            return 0;
        }
    }
    cout << "No Solution" << endl;
	return 0;
}
