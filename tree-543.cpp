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
    int res;
    
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = height(root->left);
        int right = height(root->right);
        res = max(res, left+right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        height(root);
        return res;
    }
};
