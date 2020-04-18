#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree(vector<int>::iterator inbegin, vector<int>::iterator inend, vector<int>::iterator postbegin, vector<int>::iterator postend) {
    int n = inend - inbegin;
    if (n == 0) return nullptr;
    int val = *(postend - 1);
    int nLeft = find(inbegin, inend, val) - inbegin;
    Node* root = new Node(val);
    root->left = buildTree(inbegin, inbegin + nLeft, postbegin, postbegin + nLeft);
    root->right = buildTree(inbegin + nLeft + 1, inend, postbegin + nLeft, postend - 1);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> inorder(n);
    vector<int> postorder(n);
    for (int i = 0; i < n; i++) cin >> postorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    Node* root = buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    queue<Node*> que;
    if (root == nullptr) return 0;
    cout << root->val;
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
        Node* tmp = que.front();
        que.pop();
        if (tmp == nullptr) continue;
        cout << " " << tmp->val;
        que.push(tmp->left);
        que.push(tmp->right);
    }
	return 0;
}
