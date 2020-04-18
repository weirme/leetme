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

bool convert(string& str) {
    bool flag = false;
    for (auto it = str.begin(); it < str.end(); it++) {
        switch (*it) {
            case '1':
                *it = '@';
                flag = true;
                break;
            case '0':
                *it = '%';
                flag = true;
                break;
            case 'l':
                *it = 'L';
                flag = true;
                break;
            case 'O':
                *it = 'o';
                flag = true;
                break;
            default:
                break;
        }
    }
    return flag;
}

int main() {
    vector<pair<string, string>> res;
    string id, pwd;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> pwd;
        bool flag = convert(pwd);
        if (flag) res.push_back(make_pair(id, pwd));
    }
    if (res.empty()) {
        if (n == 1)
            cout << "There is " << n << " account and no account is modified" << endl;
        else
            cout << "There are " << n << " accounts and no account is modified" << endl;
    }
    else {
        cout << res.size() << endl;
        for (auto it = res.begin(); it < res.end(); it++) {
            cout << it->first << " " << it->second << endl;
        }
    }
	return 0;
}
