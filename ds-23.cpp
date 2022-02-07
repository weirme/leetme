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
#include <algorithm>
#include "types.h"

using namespace std;

const int INF = 0x7fffffff;

struct Comp {
    bool operator() (ListNode* x, ListNode* y) {
        return x->val > y->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> que;
        for (auto p : lists) {
            if (p != nullptr) que.push(p);
        }
        ListNode * res = new ListNode(0);
        ListNode * q = res;
        while (!que.empty()) {
            ListNode * p = que.top();
            que.pop();
            q->next = p;
            q = p;
            if (p->next != nullptr) que.push(p->next);
        }
        q = res->next;
        delete res;
        return q;
    }
};
