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
    TreeNode* solve(vector<int>::iterator inBegin, vector<int>::iterator inEnd, vector<int>::iterator postBegin, vector<int>::iterator postEnd) {
        int n = inEnd - inBegin;
        if (n == 0) return nullptr;
        TreeNode* root = new TreeNode(*(postEnd-1));
        auto it = find(inBegin, inEnd, *(postEnd-1));
        int nLeft = it - inBegin;
        root->left = solve(inBegin, it, postBegin, postBegin + nLeft);
        root->right = solve(it+1, inEnd, postBegin + nLeft, postEnd-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};
