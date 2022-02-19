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
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* p = nullptr;
        vector<vector<int>> res;
        while (!que.empty()) {
            int n = que.size();
            vector<int> sol(n);
            int i = 0;
            if (res.size()&1) i = n-1;
            while (n--) {
                p = que.front();
                que.pop();
                sol[i] = p->val;
                if (res.size()&1) i--;
                else i++;
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
            res.push_back(sol);
        }
        return res;
    }
};
