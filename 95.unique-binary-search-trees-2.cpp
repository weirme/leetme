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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return construct(1, n);
    }
    
    vector<TreeNode*> construct(int front, int end) {
        if (front > end) return {nullptr};
        vector<TreeNode*> res;
        for (int i = front; i <= end; i++) {
            vector<TreeNode*> left = construct(front, i-1), right = construct(i+1, end);
            for (TreeNode* a : left) {
                for (TreeNode* b : right) {
                    TreeNode* temp = new TreeNode(i);
                    temp->left = a;
                    temp->right = b;
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};
