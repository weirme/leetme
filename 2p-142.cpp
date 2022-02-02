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
        ListNode * q = head;
        do {
            p = p->next;
            q = q->next->next;
        } while (p != q && q != nullptr && q->next != nullptr);
        if (p != q)
            return nullptr;
        int n = 1;
        q = q->next;
        while (p != q) {
            q = q->next;
            n++;
        }
        p = head;
        q = head;
        while (n--) {
            q = q->next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
