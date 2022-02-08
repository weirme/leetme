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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * p = headA;
        ListNode * q = headB;
        int m = 0, n = 0;
        while (p) {
            m++;
            p = p->next;
        }
        while (q) {
            n++;
            q = q->next;
        }
        p = headA;
        q = headB;
        if (m < n) swap(p, q);
        int k = abs(m-n);
        while (k--) {
            p = p->next;
        }
        while (p) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return nullptr;
    }
};
