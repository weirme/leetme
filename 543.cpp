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
    int solve(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int l = solve(root->left, res);
        int r = solve(root->right, res);
        res = max(res, l+r);
        return max(l, r)+1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};
