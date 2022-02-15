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
    void solve(vector<int>& sol, vector<vector<int>>& res, int k, int n, int cur, int pos) {
        if (sol.size() == k && cur == n) {
            res.push_back(sol);
            return;
        }
        if (sol.size() > k || cur > n) return;
        for (int i = pos; i <= 9; i++) {
            sol.push_back(i);
            solve(sol, res, k, n, cur+i, i+1);
            sol.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> sol;
        vector<vector<int>> res;
        solve(sol, res, k, n, 0, 1);
        return res;
    }
};
