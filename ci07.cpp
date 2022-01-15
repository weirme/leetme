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
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x3f3f3f3f;

struct TreeNode* solve(int* pre_begin, int* pre_end, int* in_begin, int* in_end) {
    struct TreeNode * root = NULL;
    if (pre_begin > pre_end)
        return root;
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = *pre_begin;
    root->left = NULL;
    root->right = NULL;
    if (pre_begin == pre_end)
        return root;
    int* p = in_begin;
    while (p < in_end && *p != *pre_begin) {
        p++;
    }
    int n_left = p - in_begin;
    root->left = solve(pre_begin + 1, pre_begin + n_left, in_begin, p - 1);
    root->right = solve(pre_begin + n_left + 1, pre_end, p + 1, in_end);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return solve(preorder, preorder + preorderSize - 1, inorder, inorder + inorderSize - 1);
}
