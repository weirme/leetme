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
        ListNode * left = new ListNode(0);
        ListNode * right = new ListNode(0);
        ListNode * l = left;
        ListNode * r = right;
        ListNode * p = head->next;
        while (p) {
            if (p->val < head->val) {
                l->next = p;
                l = p;
            }
            else {
                r->next = p;
                r = p;
            }
            p = p->next;
        }
        l->next = nullptr;
        r->next = nullptr;
        l = sortList(left->next);
        r = sortList(right->next);
        if (l == nullptr) {
            head->next = r;
        }
        else {
            p = l;
            while (p->next) {
                p = p->next;
            }
            p->next = head;
            head->next = r;
            head = l;
        }
        delete left;
        delete right;
        return head;
    }
};
