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
#include <sstream>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    TreeNode * first = nullptr;
    TreeNode * second = nullptr;
    
    void traverse(TreeNode* root, TreeNode*& pre) {
        if (root == nullptr) return;
        traverse(root->left, pre);
        if (pre != nullptr && pre->val > root->val) {
            if (first == nullptr)
                first = pre;
            second = root;
        }
        pre = root;
        traverse(root->right, pre);
    }

public:
    void recoverTree(TreeNode* root) {
        TreeNode * pre = nullptr;
        traverse(root, pre);
        swap(first->val, second->val);
    }
};

