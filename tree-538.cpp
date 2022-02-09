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
    void traverse(TreeNode* root, TreeNode* &pre) {
        if (root == nullptr) return;
        traverse(root->right, pre);
        root->val += pre->val;
        pre = root;
        traverse(root->left, pre);
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode * pre = new TreeNode(0);
        traverse(root, pre);
        return root;
    }
};
