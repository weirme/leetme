#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int N = 110;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> tree[N];
    queue< pair<int, int> > que;
    while (m--) {
        int id, k, cid;
        cin >> id >> k;
        while (k--) {
            cin >> cid;
            tree[id].push_back(cid);
        }
    }
    que.push(make_pair(1, 1));
    pair<int, int> temp;
    int level = 1;
    int cnt = 0;
    while (!que.empty()) {
        temp = que.front();
        int id = temp.first, curLevel = temp.second;
        que.pop();
        if (curLevel != level) {
            cout << cnt << " ";
            level = curLevel;
            cnt = 0;
        }
        if (tree[id].size() == 0) cnt++;
        else {
            for (auto it = tree[id].begin(); it < tree[id].end(); it++)
                que.push(make_pair(*it, curLevel+1));
        }
    }
    cout << cnt;
    return 0;
}
