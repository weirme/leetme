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

class Solution {
private:
    vector<vector<bool>> visited;
    int m, n, k;
    int sum = 0;
    
    int func(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
    
    void solve(int i, int j) {
        if (!(0 <= i && i < m) || !(0 <= j && j < n) || visited[i][j])
            return;
        visited[i][j] = true;
        if (func(i) + func(j) > k)
            return;
        sum++;
        solve(i-1, j);
        solve(i+1, j);
        solve(i, j-1);
        solve(i, j+1);
    }
    
public:
    int movingCount(int m, int n, int k) {
        this->m = m;
        this->n = n;
        this->k = k;
        for (int i = 0; i < m; i++) {
            vector<bool> vec(n);
            for (int j = 0; j < n; j++) {
                vec[j] = false;
            }
            visited.push_back(vec);
        }
        solve(0, 0);
        return sum;
    }
};
