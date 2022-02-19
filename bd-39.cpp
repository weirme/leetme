#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

class Solution {
private:
    void solve(vector<int>& nums, vector<int>& sol, vector<vector<int>>& res, int target, int cur, int pos) {
        if (cur == target) {
            res.push_back(sol);
            return;
        }
        if (cur > target) return;
        for (int i = pos; i < nums.size(); i++) {
            sol.push_back(nums[i]);
            solve(nums, sol, res, target, cur+nums[i], i);
            sol.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sol;
        vector<vector<int>> res;
        solve(candidates, sol, res, target, 0, 0);
        return res;
    }
};
