struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    TreeNode* pre = nullptr;
    
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);
        if (pre && root->val <= pre->val) return false;
        pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};
