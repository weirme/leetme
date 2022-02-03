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
    void backtrace(vector<int>& nums, vector<bool>& visited, vector<int>& sol, vector<vector<int>>& res, int sum, int target, int pos) {
        if (sum == target) {
            res.push_back(sol);
            return;
        }
        if (sum > target)
            return;
        for (int i = pos; nums[i] <= target; i++) {
            if (visited[i])
                continue;
            if (i > pos && nums[i-1] == nums[i] && !visited[i-1])
                continue;
            visited[i] = true;
            sol.push_back(nums[i]);
            sum += nums[i];
            backtrace(nums, visited, sol, res, sum, target, i+1);
            sum -= nums[i];
            sol.pop_back();
            visited[i] = false;
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        candidates.push_back(target+1);
        sort(candidates.begin(), candidates.end());
        vector<bool> visited(candidates.size(), 0);
        vector<int> sol;
        vector<vector<int>> res;
        backtrace(candidates, visited, sol, res, 0, target, 0);
        return res;
    }
};
