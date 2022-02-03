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
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    string get_path(stack<TreeNode*> stk) {
        TreeNode * p = stk.top();
        stk.pop();
        if (stk.empty()) {
            return to_string(p->val);
        }
        string res = get_path(stk);
        res += "->";
        res += to_string(p->val);
        return res;
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        stack<TreeNode*> stk;
        TreeNode * p = root;
        TreeNode * pre = nullptr;
        while (p != nullptr || !stk.empty()) {
            if (p != nullptr) {
                stk.push(p);
                p = p->left;
            }
            else {
                p = stk.top();
                if (p->right == nullptr || p->right == pre) {
                    if (p->left == nullptr && p->right == nullptr) {
                        res.push_back(get_path(stk));
                    }
                    stk.pop();
                    pre = p;
                    p = nullptr;
                }
                else {
                    p = p->right;
                }
            }
        }
        return res;
    }
};
