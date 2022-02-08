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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> que;
        que.push(root);
        TreeNode * last = root;
        int n = 0;
        int sum = 0;
        vector<double> res;
        TreeNode * cur = nullptr;
        TreeNode * p = nullptr;
        while (!que.empty()) {
            p = que.front();
            que.pop();
            n++;
            sum += p->val;
            if (p->left) {
                que.push(p->left);
                cur = p->left;
            }
            if (p->right) {
                que.push(p->right);
                cur = p->right;
            }
            if (p == last) {
                res.push_back(sum * 1.0/n);
                n = 0;
                sum = 0;
                last = cur;
            }
        }
        return res;
    }
};
