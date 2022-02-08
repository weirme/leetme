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
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * p = dummy;
        ListNode * q = head;
        ListNode * r = nullptr;
        while (q && q->next) {
            r = q->next;
            q->next = r->next;
            r->next = q;
            p->next = r;
            p = q;
            q = q->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
