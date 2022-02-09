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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int low1, int high1, int low2, int high2) {
        if (low1 > high1) return nullptr;
        TreeNode * root = new TreeNode(preorder[low1]);
        if (low1 == high1) return root;
        int v = preorder[low1+1];
        int i = low2;
        while (postorder[i] != v) i++;
        int nleft = i-low2+1;
        root->left = solve(preorder, postorder, low1+1, low1+nleft, low2, i);
        root->right = solve(preorder, postorder, low1+nleft+1, high1, i+1, high2-1);
        return root;
    }
    
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(preorder, postorder, 0, preorder.size()-1, 0, postorder.size()-1);
    }
};
