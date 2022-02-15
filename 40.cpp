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
    void solve(vector<int>& candidates, vector<bool>& visited, vector<int>& sol, vector<vector<int>>& res, int cur, int target, int pos) {
        if (cur == target) {
            res.push_back(sol);
            return;
        }
        if (cur > target) return;
        for (int i = pos; i < candidates.size(); i++) {
            if (i > 0 && !visited[i-1] && candidates[i-1] == candidates[i]) continue;
            sol.push_back(candidates[i]);
            visited[i] = true;
            solve(candidates, visited, sol, res, cur+candidates[i], target, i+1);
            visited[i] = false;
            sol.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> visited(candidates.size(), false);
        vector<int> sol;
        vector<vector<int>> res;
        solve(candidates, visited, sol, res, 0, target, 0);
        return res;
    }
};
