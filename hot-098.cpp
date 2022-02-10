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
#include <sstream>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    void solve(TreeNode* root, TreeNode* &pre, bool& flag) {
        if (root == nullptr || flag == false) return;
        solve(root->left, pre, flag);
        if (pre != nullptr && pre->val >= root->val) {
            flag = false;
            return;
        }
        pre = root;
        solve(root->right, pre, flag);
    }

public:
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        TreeNode * pre = nullptr;
        solve(root, pre, flag);
        return flag;
    }
};
