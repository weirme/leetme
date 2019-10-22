struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return judge(root->left, root->right);
    }
    
    bool judge(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left != nullptr && right != nullptr)
            return left->val == right->val
                && judge(left->left, right->right)
                && judge(left->right, right->left);
        return false;
    }
};
