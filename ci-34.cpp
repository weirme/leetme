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
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> res;
        vector<TreeNode*> stk;
        vector<int> val;
        int sum = 0;
        TreeNode* p = root;
        TreeNode* pre = nullptr;
        while (p || !stk.empty()) {
            if (p) {
                stk.push_back(p);
                val.push_back(p->val);
                sum += p->val;
                p = p->left;
            }
            else {
                p = stk.back();
                if (p->right == nullptr || p->right == pre) {
                    if (p->left == nullptr && p->right == nullptr
                        && sum == target) {
                        res.push_back(val);
                    }
                    stk.pop_back();
                    val.pop_back();
                    sum -= p->val;
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
