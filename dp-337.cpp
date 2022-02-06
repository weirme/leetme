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
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    const pair<int, int> solve(TreeNode * root) {
        if (root == nullptr)
            return {0, 0};
        pair<int, int> res;
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        res.first = max(left.first, left.second) + max(right.first, right.second);
        res.second = root->val + left.first + right.first;
        return res;
    }
    
public:
    int rob(TreeNode* root) {
        auto& [a, b] = solve(root);
        return max(a, b);
    }
};
