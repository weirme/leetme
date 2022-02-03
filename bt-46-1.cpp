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
    void solve(vector<int>& nums, vector<bool>& visited, vector<int>& sol, vector<vector<int>>& res) {
        if (sol.size() == nums.size()) {
            res.push_back(sol);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                sol.push_back(nums[i]);
                solve(nums, visited, sol, res);
                sol.pop_back();
                visited[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> sol;
        solve(nums, visited, sol, res);
        return res;
    }
};
