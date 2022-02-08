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
    int solve(TreeNode* root, bool& flag) {
        if (root == nullptr) return 0;
        int l = solve(root->left, flag);
        if (flag == false) return -1;
        int r = solve(root->right, flag);
        if (flag == false) return -1;
        flag = (abs(l-r) <= 1);
        return max(l, r) + 1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        solve(root, flag);
        return flag;
    }
};
