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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode * p = root;
        while (p || !stk.empty()) {
            if (p) {
                res.push_back(p->val);
                stk.push(p);
                p = p->left;
            }
            else {
                p = stk.top();
                stk.pop();
                p = p->right;
            }
        }
        return res;
    }
};
