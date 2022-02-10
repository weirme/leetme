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
    int res = -INF;
    
    int solve(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = max(solve(root->left), 0);
        int r = max(solve(root->right), 0);
        res = max(res, root->val+l+r);
        return root->val + max(max(l, r), 0);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return res;
    }
};
