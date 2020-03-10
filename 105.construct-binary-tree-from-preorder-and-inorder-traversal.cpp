#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int nLeft = it - inorder.begin();
        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+nLeft+1);
        vector<int> rightPreorder(preorder.begin()+nLeft+1, preorder.end());
        vector<int> leftInorder(inorder.begin(), it);
        vector<int> rightInorder(it+1, inorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};
