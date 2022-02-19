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

struct cmp{
    bool operator()(ListNode* x, ListNode* y) {
        return x->val < y->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        ListNode* dummy = new ListNode(0);
        ListNode* r = dummy;
        ListNode* p = nullptr;
        for (auto p : lists) {
            if (p) que.push(p);
        }
        while (!que.empty()) {
            p = que.top();
            que.pop();
            if (p->next) que.push(p->next);
            r->next = p;
            r = p;
        }
        return dummy->next;
    }
};
