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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int plow, int phigh, int ilow, int ihigh) {
        if (plow > phigh) return nullptr;
        int v = preorder[plow];
        int i = ilow;
        while (inorder[i] != v) i++;
        int nleft = i - ilow;
        TreeNode * left = solve(preorder, inorder, plow+1, plow+nleft, ilow, i-1);
        TreeNode * right = solve(preorder, inorder, plow+nleft+1, phigh, i+1, ihigh);
        TreeNode * root = new TreeNode(v);
        root->left = left;
        root->right = right;
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
