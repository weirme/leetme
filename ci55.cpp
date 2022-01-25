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
    bool height(TreeNode * root, int& h) {
        if (root == nullptr) {
            h = 0;
            return true;
        }
        int h1, h2;
        bool left = height(root->left, h1);
        if (left == false)
            return false;
        bool right = height(root->right, h2);
        if (right == false)
            return false;
        if (abs(h1 - h2) > 1)
            return false;
        h = max(h1, h2) + 1;
        return true;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        int h = 0;
        return height(root, h);
    }
};
