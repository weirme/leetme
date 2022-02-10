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
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* p = root;
        TreeNode* pre = new TreeNode(0);
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p->right);
                pre->left = nullptr;
                pre->right = p;
                pre = p;
                p = p->left;
            }
            else {
                p = stk.top();
                stk.pop();
            }
        }
        pre->left = nullptr;
        pre->right = nullptr;
        return;
    }
};
