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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode * last = root;
        TreeNode * t = nullptr;
        vector<int> level = {};
        while (!que.empty()) {
            t = que.front();
            que.pop();
            level.push_back(t->val);
            if (t->left)
                que.push(t->left);
            if (t->right)
                que.push(t->right);
            if (t == last) {
                res.push_back(level);
                level = {};
                last = que.back();
            }
        }
        return res;
    }
};
