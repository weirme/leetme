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
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;
        ListNode* p = head;
        ListNode* q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
        }
        ListNode* h = nullptr;
        ListNode* t = nullptr;
        q = p->next;
        p->next = nullptr;
        while (q) {
            t = q->next;
            q->next = h;
            h = q;
            q = t;
        }
        p = head;
        q = h;
        while (q) {
            t = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = t;
        }
    }
};
