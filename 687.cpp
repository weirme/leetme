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
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        pair<int, int> l = {0, 0}, r = {0, 0};
        if (root->left && root->left->val == root->val) l = solve(root->left);
        if (root->right && root->right->val == root->val) r = solve(root->right);
        return {l.second + r.second + 1, max(l.second, r.second) + 1};
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) return 0;
        pair<int, int> res = solve(root);
        return max({res.first-1, res.second-1, longestUnivaluePath(root->left), longestUnivaluePath(root->right)});
    }
};
