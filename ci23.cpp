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
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode * p = head;
        ListNode * q = head->next;
        while (q != nullptr && q->next != nullptr) {
            if (p == q)
                break;
            p = p->next;
            q = q->next->next;
        }
        if (p != q)
            return nullptr;
        int len = 0;
        do {
            q = q->next;
            len++;
        } while (p != q);
        p = head;
        q = head;
        while (len--) {
            p = p->next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return q;
    }
};
