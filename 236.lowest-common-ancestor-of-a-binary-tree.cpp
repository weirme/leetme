struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* res = nullptr;

    bool traverse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        bool left = traverse(root->left, p, q);
        bool mid = (root == p || root == q);
        bool right = traverse(root->right, p, q);
        if (left && mid || left && right || mid && right) res = root;
        if (left || mid || right) return true;
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        traverse(root, p, q);
        return res;
    }
};