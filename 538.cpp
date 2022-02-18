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
    void solve(TreeNode* root, TreeNode* &pre) {
        if (root == nullptr) return;
        solve(root->right, pre);
        root->val += pre->val;
        pre = root;
        solve(root->left, pre);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* pre = new TreeNode(0);
        solve(root, pre);
        return root;
    }
};
