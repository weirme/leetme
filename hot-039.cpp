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
    void solve(vector<int>& nums, vector<int>& sol, vector<vector<int>>& res, int target, int sum, int pos) {
        if (sum == target) {
            res.push_back(sol);
            return;
        }
        if (sum > target) return;
        for (int i = pos; i < nums.size(); i++) {
            sol.push_back(nums[i]);
            solve(nums, sol, res, target, sum+nums[i], i);
            sol.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        solve(candidates, sol, res, target, 0, 0);
        return res;
    }
};
