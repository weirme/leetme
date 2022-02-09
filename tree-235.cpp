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
        int mi = min(p->val, q->val);
        int mx = max(p->val, q->val);
        if (mi <= root->val && root->val <= mx) return root;
        if (root->val < mi) return lowestCommonAncestor(root->right, p, q);
        if (root->val > mx) return lowestCommonAncestor(root->left, p, q);
        return nullptr;
    }
};
