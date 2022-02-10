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
    void solve(vector<int>& nums, vector<int>& sol, vector<vector<int>>& res, int pos) {
        if (pos == nums.size()) {
            res.push_back(sol);
            return;
        }
        solve(nums, sol, res, pos+1);
        sol.push_back(nums[pos]);
        solve(nums, sol, res, pos+1);
        sol.pop_back();
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;
        solve(nums, sol, res, 0);
        return res;
    }
};
