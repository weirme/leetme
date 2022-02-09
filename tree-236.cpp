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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> que;
        vector<TreeNode*> path;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        bool flag = false;
        while (cur || !que.empty()) {
            if (cur) {
                que.push_back(cur);
                cur = cur->left;
            }
            else {
                cur = que.back();
                if (cur->right == nullptr || cur->right == pre) {
                    if (p == cur || q == cur) {
                        if (flag == false) {
                            for (int i = 0; i < que.size(); i++)
                                path.push_back(que[i]);
                            flag = true;
                        }
                        else {
                            TreeNode * res;
                            for (int i = 0; i < path.size() && i < que.size(); i++)
                                if (path[i] == que[i]) res = path[i];
                            return res;
                        }
                    }
                    que.pop_back();
                    pre = cur;
                    cur = nullptr;
                }
                else cur = cur->right;
            }
        }
        return nullptr;
    }
};
