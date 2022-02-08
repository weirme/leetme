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
    int solve(TreeNode* root, int target) {
        if (root == nullptr) return 0;
        int l = solve(root->left, target-root->val);
        int r = solve(root->right, target-root->val);
        return l + r + (root->val == target);
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        return solve(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
