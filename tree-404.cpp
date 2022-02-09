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
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode * p = root;
        int res = 0;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                p = p->left;
            }
            else {
                p = stk.top();
                stk.pop();
                if (p->left == nullptr && p->right == nullptr && !stk.empty() && p == stk.top()->left)
                    res += p->val;
                p = p->right;
            }
        }
        return res;
    }
};
