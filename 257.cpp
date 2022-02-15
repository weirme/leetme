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
    string path(vector<TreeNode*>& stk) {
        string res = {to_string(stk[0]->val)};
        for (int i = 1; i < stk.size(); i++) {
            res = res + "->" + to_string(stk[i]->val);
        }
        return res;
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<TreeNode*> stk;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        vector<string> res;
        while (p || !stk.empty()) {
            if (p) {
                stk.push_back(p);
                p = p->left;
            }
            else {
                p = stk.back();
                if (p->right == nullptr || p->right == pre) {
                    if (p->left == nullptr && p->right == nullptr) {
                        res.push_back(path(stk));
                    }
                    stk.pop_back();
                    pre = p;
                    p = nullptr;
                }
                else p = p->right;
            }
        }
        return res;
    }
};
