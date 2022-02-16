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
        pair<int, int> l = solve(root->left);
        pair<int, int> r = solve(root->right);
        return {
            max(l.first, l.second) + max(r.first, r.second),
            root->val + l.first + r.first
        };
    }
    
public:
    int rob(TreeNode* root) {
        pair<int, int> p = solve(root);
        return max(p.first, p.second);
    }
};
