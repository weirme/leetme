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
#include <sstream>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    void solve(TreeNode* &root, int key) {
        if (root == nullptr) return;
        if (root->val == key) {
            if (root->left && root->right) {
                TreeNode* p = root->left;
                while (p->right) {
                    p = p->right;
                }
                swap(root->val, p->val);
                solve(root->left, key);
            }
            else if (root->left)
                root = root->left;
            else if (root->right)
                root = root->right;
            else
                root = nullptr;
        }
        else if (root->val < key) solve(root->right, key);
        else solve(root->left, key);
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        solve(root, key);
        return root;
    }
};
