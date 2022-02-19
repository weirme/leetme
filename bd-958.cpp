#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* p = nullptr;
        bool flag = true;
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                p = que.front();
                que.pop();
                if (p->left) {
                    if (flag == false) return false;
                    que.push(p->left);
                }
                else flag = false;
                if (p->right) {
                    if (flag == false) return false;
                    que.push(p->right);
                }
                else flag = false;
            }
        }
        return true;
    }
};
