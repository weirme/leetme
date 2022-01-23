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
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        stack<TreeNode *> stk;
        TreeNode * p = root;
        while (p != nullptr || !stk.empty()) {
            if (p) {
                stk.push(p);
                p = p->right;
            }
            else {
                p = stk.top();
                stk.pop();
                if (--k == 0) {
                    return p->val;
                }
                p = p->left;
            }
        }
        return INF;
    }
};
