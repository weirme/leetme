#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > res;
        queue< pair<TreeNode*, int> > que;
        pair<TreeNode*, int> cur;
        vector<int> tmp;
        if (root == nullptr) return res;
        que.push(make_pair(root, 0));
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            if (cur.first == nullptr) continue;
            if (cur.second > res.size()) {
                if (tmp.size() > 0) res.push_back(tmp);
                tmp = {};
            }
            tmp.push_back(cur.first->val);
            que.push(make_pair(cur.first->left, cur.second+1));
            que.push(make_pair(cur.first->right, cur.second+1));
        }
        if (!tmp.empty()) res.push_back(tmp);
        return res;
    }
};
