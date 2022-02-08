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
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode * p = head;
        ListNode * q = head->next;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = nullptr;
        ListNode * left = sortList(head);
        ListNode * right = sortList(q);
        ListNode * dummy = new ListNode(0);
        ListNode * r = dummy;
        p = left;
        q = right;
        while (p && q) {
            if (p->val < q->val) {
                r->next = p;
                r = p;
                p = p->next;
            }
            else {
                r->next = q;
                r = q;
                q = q->next;
            }
        }
        if (p) r->next = p;
        if (q) r->next = q;
        r = dummy->next;
        delete dummy;
        return r;
    }
};
