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

using namespace std;

const int INF = 0x3f3f3f3f;

struct Node {
    int val;
    struct Node * parent;
    struct Node * left;
    struct Node * right;
};


struct Node * findNext(struct Node * node) {
    if (node == NULL)
        return NULL;
    struct Node * res = NULL;
    if (node->right != NULL) {
        res = node->right;
        while (res->left != NULL) {
            res = res->left;
        }
    }
    else if (node->parent != NULL) {
        res = node;
        while (res->parent != NULL && res->parent->right == res) {
            res = res->parent;
        }
    }
    return res;
}
