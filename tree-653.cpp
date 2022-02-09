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
    bool findTarget(TreeNode* root, int k) {
        static unordered_set<int> set;
        if (root == nullptr) return false;
        findTarget(root->left, k);
        if (set.find(k-root->val) != set.end()) return true;
        set.insert(root->val);
        findTarget(root->right, k);
        return false;
    }
};
