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
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode * left = root->left;
        TreeNode * right = root->right;
        root->left = mirrorTree(right);
        root->right = mirrorTree(left);
        return root;
    }
};
