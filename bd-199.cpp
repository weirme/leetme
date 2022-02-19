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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* p = nullptr;
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                p = que.front();
                que.pop();
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            res.push_back(p->val);
        }
        return res;
    }
};
