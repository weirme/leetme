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
        if (B == nullptr)
            return true;
        if (A == nullptr)
            return false;
        if (A->val != B->val)
            return false;
        return solve(A->left, B->left) && solve(A->right, B->right);
    }
    
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        bool res = false;
        if (A->val == B->val)
            res = solve(A, B);
        if (res == false)
            res = isSubStructure(A->left, B) || isSubStructure(A->right, B);
        return res;
    }
};
