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

class Codec {
private:
    int pos = 0;
    
    int next(string data) {
        int res = 0;
        int flag = 1;
        if (data[pos] == '-') {
            flag = -1;
            pos++;
        }
        while (pos < data.size() && data[pos] != ',') {
            res = res * 10 + data[pos++]-'0';
        }
        pos++;
        return flag * res;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val) + ',' + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data[pos] == '#') {
            pos++;
            return nullptr;
        }
        TreeNode * root = new TreeNode(next(data));
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};

