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
#include <unordered_map>
#include <algorithm>

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    void solve(vector<int>& comb, vector<vector<int>>& res, int cnt, int pos, int k, int n) {
        if (cnt == k) {
            res.push_back(comb);
            return;
        }
        for (int i = pos; i <= n; i++) {
            comb[cnt] = i;
            solve(comb, res, cnt+1, i+1, k, n);
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb(k, 0);
        solve(comb, res, 0, 1, k, n);
        return res;
    }
};
