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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        stack<bool> flag_st;
        vector<int> res;
        TreeNode* cur = nullptr;
        bool flag;
        if (root == nullptr) return res;
        st.push(root);
        flag_st.push(true);
        while (!st.empty()) {
            cur = st.top();
            flag = flag_st.top();
            if (cur->left != nullptr && flag) {
                flag_st.top() = false;
                st.push(cur->left);
                flag_st.push(true);
            }
            else if (cur->right != nullptr) {
                res.push_back(cur->val);
                cur = cur->right;
                st.pop();
                flag_st.pop();
                st.push(cur);
                flag_st.push(true);
            }
            else {
                res.push_back(cur->val);
                st.pop();
                flag_st.pop();
            }
        }
        return res;
    }
};
