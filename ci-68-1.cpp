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
    vector<TreeNode*> path;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> stk;
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push_back(cur);
                cur = cur->left;
            }
            else {
                cur = stk.back();
                if (cur->right == nullptr || cur->right == pre) {
                    if (cur == p || cur == q) {
                        if (path.empty()) path = stk;
                        else {
                            int i = 0;
                            while(i < path.size() && i < stk.size() && path[i] == stk[i]) i++;
                            return stk[i-1];
                        }
                    }
                    stk.pop_back();
                    pre = cur;
                    cur = nullptr;
                }
                else cur = cur->right;
            }
        }
        return nullptr;
    }
};
