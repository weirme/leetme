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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return root;
        int mi = min(p->val, q->val);
        int ma = max(p->val, q->val);
        if (root->val < mi) return lowestCommonAncestor(root->right, p, q);
        if (root->val > ma) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};
