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
private:
    bool solve(TreeNode* A, TreeNode* B) {
        if (!A && !B)
            return true;
        if (A && B) {
            return A->val == B->val
                && solve(A->left, B->right)
                && solve(A->right, B->left);
        }
        return false;
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return solve(root->left, root->right);
    }
};
