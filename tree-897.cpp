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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode * head = nullptr;
        TreeNode * pre = nullptr;
        TreeNode * p = root;
        stack<TreeNode*> stk;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                TreeNode * l = p->left;
                p->left = nullptr;
                p = l;
            }
            else {
                p = stk.top();
                stk.pop();
                TreeNode * r = p->right;
                if (pre == nullptr) head = p;
                else {
                    pre->right = p;
                }
                pre = p;
                p = r;
            }
        }
        return head;
    }
};
