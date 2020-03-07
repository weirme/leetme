#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > res;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            vector<int> v1, v2;
            while (!s1.empty()) {
                TreeNode* t = s1.top();
                s1.pop();
                if (t == nullptr) continue;
                v1.push_back(t->val);
                s2.push(t->left);
                s2.push(t->right);
            }
            if (!v1.empty()) res.push_back(v1);
            while (!s2.empty()) {
                TreeNode* t = s2.top();
                s2.pop();
                if (t == nullptr) continue;
                v2.push_back(t->val);
                s1.push(t->right);
                s1.push(t->left);
            }
            if (!v2.empty()) res.push_back(v2);
        }
        
        return res;
    }
};
