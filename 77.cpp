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
#include <unordered_set>
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    void solve(vector<int>& sol, vector<vector<int>>& res, int n, int k, int pos) {
        if (sol.size() == k) {
            res.push_back(sol);
            return;
        }
        for (int i = pos; i <= n; i++) {
            sol.push_back(i);
            solve(sol, res, n, k, i+1);
            sol.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> sol;
        vector<vector<int>> res;
        solve(sol, res, n, k, 1);
        return res;
    }
};
