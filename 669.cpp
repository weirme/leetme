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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return root;
        TreeNode* l = trimBST(root->left, low, high);
        TreeNode* r = trimBST(root->right, low, high);
        if (low <= root->val && root->val <= high) {
            root->left = l;
            root->right = r;
        }
        else if (root->val < low) root = r;
        else root = l;
        return root;
    }
};
