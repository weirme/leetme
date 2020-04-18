#include <cmath>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue< pair<TreeNode*, int> > que;
        vector<int> vec;
        vector< vector<int> > res;
        pair<TreeNode*, int> t;
        int cur = 0;
        que.push(make_pair(root, 0));
        while (!que.empty()) {
            t = que.front();
            que.pop();
            if (t.second != cur) {
                res.push_back(vec);
                vec.clear();
                cur++;
            }
            if (t.first != nullptr) {
                vec.push_back(t.first->val);
                que.push(make_pair(t.first->left, t.second+1));
                que.push(make_pair(t.first->right, t.second+1));
            }
        }
        res.push_back(vec);
        reverse(res.begin(), res.end());
        return res;
    }
};
