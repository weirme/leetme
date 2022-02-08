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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode * dummy = new ListNode(0);
        ListNode * p = head;
        ListNode * q = dummy;
        while (p->next) {
            ListNode * t = p->next;
            p->next = t->next;
            if (p->next)
                p = p->next;
            q->next = t;
            q = t;
        }
        q->next = nullptr;
        p->next = dummy->next;
        delete dummy;
        return head;
    }
};
