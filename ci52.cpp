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
#include "types.h"

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution {
public:
    ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0, n2 = 0;
        ListNode * p = headA;
        ListNode * q = headB;
        while (p != nullptr) {
            n1++;
            p = p->next;
        }
        while (q != nullptr) {
            n2++;
            q = q->next;
        }
        int k = n2 - n1;
        p = headA;
        q = headB;
        if (k < 0) {
            k = -k;
            swap(p, q);
        }
        while (k--) {
            q = q->next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
