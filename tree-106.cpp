#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
private:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int low1, int high1, int low2, int high2) {
        if (low1 > high1) return nullptr;
        TreeNode* root = new TreeNode(postorder[high2]);
        int v = postorder[high2];
        int i = low1;
        while (inorder[i] != v) i++;
        int nleft = i-low1;
        root->left = solve(inorder, postorder, low1, i-1, low2, low2+nleft-1);
        root->right = solve(inorder, postorder, i+1, high1, low2+nleft, high2-1);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
};
