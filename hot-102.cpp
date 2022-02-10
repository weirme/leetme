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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> que;
        que.push(root);
        TreeNode * p = nullptr;
        TreeNode * last = root;
        TreeNode * pre = root;
        vector<vector<int>> res;
        vector<int> cur;
        while (!que.empty()) {
            p = que.front();
            que.pop();
            cur.push_back(p->val);
            if (p->left) {
                que.push(p->left);
                pre = p->left;
            }
            if (p->right) {
                que.push(p->right);
                pre = p->right;
            }
            if (p == last) {
                res.push_back(cur);
                cur = {};
                last = pre;
            }
        }
        return res;
    }
};
