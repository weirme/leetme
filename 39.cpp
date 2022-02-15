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
    void solve(vector<int>& candidates, vector<int>& sol, vector<vector<int>>& res, int cur, int target, int pos) {
        if (cur == target) {
            res.push_back(sol);
            return;
        }
        if (cur > target) return;
        for (int i = pos; i < candidates.size(); i++) {
            sol.push_back(candidates[i]);
            solve(candidates, sol, res, cur+candidates[i], target, i);
            sol.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        vector<vector<int>> res;
        solve(candidates, sol, res, 0, target, 0);
        return res;
    }
};
