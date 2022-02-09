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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* left = root;
        TreeNode* last = root;
        TreeNode* pre = nullptr;
        TreeNode* p = nullptr;
        while (!que.empty()) {
            p = que.front();
            que.pop();
            if (p->left) {
                que.push(p->left);
                pre = p->left;
            }
            if (p->right) {
                que.push(p->right);
                pre = p->right;
            }
            if (p == last) {
                last = pre;
                if (!que.empty()) left = que.front();
            }
        }
        return left->val;
    }
};
