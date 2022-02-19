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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<stack<TreeNode*>> stk(2);
        vector<vector<int>> res;
        TreeNode* p = nullptr;
        int i = 0, j = 1;
        stk[i].push(root);
        while (!stk[i].empty()) {
            int n = stk[i].size();
            vector<int> sol;
            while (n--) {
                p = stk[i].top();
                stk[i].pop();
                sol.push_back(p->val);
                if (i == 0) {
                    if (p->left) stk[j].push(p->left);
                    if (p->right) stk[j].push(p->right);
                }
                else {
                    if (p->right) stk[j].push(p->right);
                    if (p->left) stk[j].push(p->left);
                }
            }
            res.push_back(sol);
            swap(i, j);
        }
        return res;
    }
};
