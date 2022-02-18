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
private:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = left;
        ListNode* q = right;
        ListNode* r = dummy;
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
        return dummy->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p = head;
        ListNode* q = head->next;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = nullptr;
        ListNode* l = sortList(head);
        ListNode* r = sortList(q);
        return merge(l, r);
    }
};
