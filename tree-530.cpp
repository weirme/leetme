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
    int res = INF;
    
    void solve(TreeNode* root, TreeNode* &pre) {
        if (root == nullptr) return;
        solve(root->left, pre);
        res = min(res, root->val - pre->val);
        pre = root;
        solve(root->right, pre);
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode * pre = new TreeNode(-1e6);
        solve(root, pre);
        return res;
    }
};
