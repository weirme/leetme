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
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    int target;
    
    void solve(TreeNode * root) {
        if (root == nullptr)
            return;
        sum += root->val;
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == target) {
            vector<int> t(path);
            res.push_back(t);
        }
        if (root->left)
            solve(root->left);
        if (root->right)
            solve(root->right);
        sum -= root->val;
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        this->target = target;
        solve(root);
        return res;
    }
};
