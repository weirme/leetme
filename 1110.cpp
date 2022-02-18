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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<TreeNode*> set;
        stack<TreeNode*> stk;
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        to_delete.push_back(0);
        TreeNode* p = dummy;
        TreeNode* pre = nullptr;
        vector<TreeNode*> res;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                p = p->left;
            }
            else {
                p = stk.top();
                if (p->right == nullptr || p->right == pre) {
                    if (p->left && set.find(p->left) != set.end()) p->left = nullptr;
                    if (p->right && set.find(p->right) != set.end()) p->right = nullptr;
                    if (find(to_delete.begin(), to_delete.end(), p->val) != to_delete.end()) {
                        if (p->left) res.push_back(p->left);
                        if (p->right) res.push_back(p->right);
                        set.insert(p);
                    }
                    stk.pop();
                    pre = p;
                    p = nullptr;
                }
                else p = p->right;
            }
        }
        return res;
    }
};
