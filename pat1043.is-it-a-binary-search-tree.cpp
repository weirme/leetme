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

vector<int> post;
int flag = 0;

bool getpost(vector<int>::iterator front, vector<int>::iterator rear) {
    if (front > rear) return true;
    auto root = front;
    auto it1 = front+1;
    auto it2 = rear;
    if (flag == 0) {
        while (it1 <= rear && *it1 < *root) it1++;
        while (it2 > front  && *it2 >= *root) it2--;
    }
    else {
        while (it1 <= rear && *it1 >= *root) it1++;
        while (it2 > front && *it2 < *root) it2--;
    }
    if (it2 + 1 == it1 && getpost(front+1, it2) && getpost(it1, rear)) {
        post.push_back(*root);
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; i++) cin >> vals[i];
    bool res1 = getpost(vals.begin(), vals.end()-1);
    if (res1) {
        cout << "YES" << endl << *post.begin();
        for (auto it = post.begin()+1; it < post.end(); it++)
            cout << " " << *it;
        return 0;
    }
    flag = 1;
    post.clear();
    bool res2 = getpost(vals.begin(), vals.end()-1);
    if (res2) {
        cout << "YES" << endl << *post.begin();
        for (auto it = post.begin()+1; it < post.end(); it++)
            cout << " " << *it;
        return 0;
    }
    cout << "NO" << endl;
	return 0;
}
