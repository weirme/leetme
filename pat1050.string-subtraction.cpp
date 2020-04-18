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
    bool dict[128] = {0};
    string str;
    string sub;
    getline(cin, str);
    getline(cin, sub);
    for (auto c : sub) dict[c] = true;
    vector<char> res;
    for (auto c : str) {
        if (!dict[c]) res.push_back(c);
    }
    for (auto c : res) {
        cout << c;
    }
	return 0;
}
