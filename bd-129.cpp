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

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        vector<TreeNode*> stk;
        int res = 0;
        int cur = 0;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        while (p || !stk.empty()) {
            if (p) {
                stk.push_back(p);
                cur = cur*10 + p->val;
                p = p->left;
            }
            else {
                p = stk.back();
                if (p->right == nullptr || p->right == pre) {
                    if (p->left == nullptr && p->right == nullptr) {
                        res += cur;
                    }
                    stk.pop_back();
                    cur /= 10;
                    pre = p;
                    p = nullptr;
                }
                else p = p->right;
            }
        }
        return res;
    }
};
