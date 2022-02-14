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

/*
 slow * 2 = fast;
 slow = a + b;
 fast = a + b + c + b = a + 2*b + c;
 (a + b)*2 = a + 2*b + c;
 a = c;
 a：入环距离
 b：慢指针入环所走距离[慢指针入环后，快指针所走距离的一半]
 c：快指针入环后，抽风等待慢指针入环的距离。
 综上，快指针先走了a入环，然后开始抽风的转圈走了c，这时慢指针入环，t相同，v快 = 2v慢，s快 = 2s慢，
 即：a + b = a + c + 2b => a = c
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode* p = head;
        ListNode* q = head;
        do {
            p = p->next->next;
            q = q->next;
        } while (p && p->next && p != q);
        if (p != q) return nullptr;
        p = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
