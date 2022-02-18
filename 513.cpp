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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        TreeNode* p = nullptr;
        while (!que.empty()) {
            int n = que.size();
            res = que.front()->val;
            while (n--) {
                p = que.front();
                que.pop();
                if (p->left) que.push(p->left);
                if (p->right) que.push(p->right);
            }
        }
        return res;
    }
};
