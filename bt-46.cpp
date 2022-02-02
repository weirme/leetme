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
    void solve(vector<int>& nums, int begin, vector<vector<int>>& res) {
        if (begin == nums.size()-1) {
            res.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);
            solve(nums, begin+1, res);
            swap(nums[begin], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums, 0, res);
        return res;
    }
};
