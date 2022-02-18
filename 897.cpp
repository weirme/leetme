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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = nullptr;
        TreeNode* pre = nullptr;
        TreeNode* p = root;
        stack<TreeNode*> stk;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                p = p->left;
            }
            else {
                p = stk.top();
                stk.pop();
                if (pre == nullptr) {
                    head = p;
                }
                else {
                    pre->left = nullptr;
                    pre->right = p;
                }
                pre = p;
                p = p->right;
            }
        }
        pre->left = nullptr;
        pre->right = nullptr;
        return head;
    }
};
