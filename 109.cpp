#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return new TreeNode(head->val);
        ListNode* p = head;
        ListNode* q = head->next->next;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = nullptr;
        TreeNode* left = sortedListToBST(head);
        TreeNode* root = new TreeNode(q->val);
        TreeNode* right = sortedListToBST(q->next);
        root->left = left;
        root->right = right;
        return root;
    }
};
