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
    void solve(vector<int>& nums, vector<bool>& visited, vector<int>& sol, vector<vector<int>>& res) {
        if (sol.size() == nums.size()) {
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (i > 0 && nums[i-1] == nums[i] && !visited[i-1]) continue;
            sol.push_back(nums[i]);
            visited[i] = true;
            solve(nums, visited, sol, res);
            visited[i] = false;
            sol.pop_back();
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int> sol;
        vector<vector<int>> res;
        solve(nums, visited, sol, res);
        return res;
    }
};
