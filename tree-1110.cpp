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
private:
    vector<TreeNode*> res;
    
    void solve(TreeNode *& pre, TreeNode * p, unordered_set<int>& set) {
        if (p == nullptr) return;
        if (set.find(p->val) != set.end()) {
            if (pre->left == p) pre->left = nullptr;
            else pre->right = nullptr;
            if (p->left && set.find(p->left->val) == set.end()) res.push_back(p->left);
            if (p->right && set.find(p->right->val) == set.end()) res.push_back(p->right);
        }
        solve(p, p->left, set);
        solve(p, p->right, set);
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set;
        set.insert(0);
        for (int n : to_delete) set.insert(n);
        TreeNode * dummy1 = new TreeNode(0);
        TreeNode * dummy2 = new TreeNode(0);
        dummy1->left = dummy2;
        dummy2->left = root;
        solve(dummy1, dummy2, set);
        delete dummy1;
        delete dummy2;
        return res;
    }
};
