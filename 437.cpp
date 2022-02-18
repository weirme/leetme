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

const int INF = 0x7fffffff;

class Solution {
private:
    void solve(TreeNode* root, int targetSum, int cur, int& res) {
        if (root == nullptr) return;
        cur += root->val;
        if (cur == targetSum) res++;
        solve(root->left, targetSum, cur, res);
        solve(root->right, targetSum, cur, res);
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        int res = 0;
        solve(root, targetSum, 0, res);
        res += pathSum(root->left, targetSum);
        res += pathSum(root->right, targetSum);
        return res;
    }
};
