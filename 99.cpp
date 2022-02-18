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
public:
    void recoverTree(TreeNode* root) {
        TreeNode* begin = nullptr;
        TreeNode* end = nullptr;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        stack<TreeNode*> stk;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                p = p->left;
            }
            else {
                p = stk.top();
                stk.pop();
                if (pre && pre->val > p->val) {
                    if (begin == nullptr) begin = pre;
                    end = p;
                }
                pre = p;
                p = p->right;
            }
        }
        swap(begin->val, end->val);
    }
};
