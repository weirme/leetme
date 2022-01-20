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

class Codec {
private:
    string str;
    int idx = 0;
    
    void encode(TreeNode* root) {
        if (root == nullptr) {
            str.push_back('$');
            return;
        }
        str.push_back(root->val);
        encode(root->left);
        encode(root->right);
    }
    
    TreeNode* decode() {
        TreeNode* root = nullptr;
        if (str[idx] == '$') {
            idx++;
            return root;
        }
        root = new TreeNode(str[idx++]);
        root->left = decode();
        root->right = decode();
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        encode(root);
        string res(str);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        str = data;
        return decode();
    }
};
