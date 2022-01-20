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

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
private:
    Node* pre = nullptr;
    Node* head = nullptr;
    
    void solve(Node* root, Node* &pre) {
        if (root == nullptr)
            return;
        solve(root->left, pre);
        root->left = pre;
        if (pre == nullptr)
            head = root;
        else
            pre->right = root;
        pre = root;
        solve(root->right, pre);
    }
    
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return nullptr;
        solve(root, pre);
        Node* p = head;
        while (p->right != nullptr) {
            p = p->right;
        }
        head->left = p;
        p->right = head;
        return head;
    }
};
