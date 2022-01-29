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
#include <list>
#include <sstream>
#include "types.h"

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
private:
    list<TreeNode *> traverse(TreeNode * root, TreeNode * p) {
        list<TreeNode *> stk;
        TreeNode * q = root;
        TreeNode * r = nullptr;
        while (q != nullptr || !stk.empty()) {
            if (q != nullptr) {
                stk.push_back(q);
                q = q->left;
            }
            else {
                q = stk.back();
                if (q->right == nullptr || q->right == r) {
                    if (q == p)
                        break;
                    r = q;
                    q = nullptr;
                    stk.pop_back();
                }
                else {
                    q = q->right;
                }
            }
        }
        return stk;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        list<TreeNode *> stk1 = traverse(root, p);
        list<TreeNode *> stk2 = traverse(root, q);
        TreeNode * res = nullptr;
        auto it1 = stk1.begin(), it2 = stk2.begin();
        while (it1 != stk1.end() && it2 != stk2.end()) {
            if (*it1 == *it2) {
                res = *it1;
                it1++;
                it2++;
            }
            else {
                break;
            }
        }
        return res;
    }
};
